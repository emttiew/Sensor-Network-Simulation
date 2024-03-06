#pragma once

#include <boost/circular_buffer.hpp>
#include <condition_variable>
#include <mutex>
#include <thread>

#include "Client.hpp"

class MainNode {
 public:
  explicit MainNode(int bufferSize) : buffer(bufferSize) {}

  void receiveData(int data) {
    std::lock_guard<std::mutex> lock(mutex);

    buffer.push_back(data);

    // Notify clients if it's time
    auto now = std::chrono::system_clock::now();
    if (now - lastNotificationTime >= std::chrono::seconds(1)) {
      condVar.notify_one();
      lastNotificationTime = now;
    }
  }

  void start() {
    std::thread notifyThread(&MainNode::notifyClients, this);
    notifyThread.detach();
  }

  void addClient(Client& client) { clients.push_back(client); }

 private:
  boost::circular_buffer<int> buffer;
  std::mutex mutex;
  std::condition_variable condVar;
  std::vector<std::reference_wrapper<Client>> clients;
  std::chrono::system_clock::time_point lastNotificationTime;

  void notifyClients() {
    while (true) {
      std::unique_lock<std::mutex> lock(mutex);

      condVar.wait(lock);

      for (int data : buffer) {
        for (Client& client : clients) {
          client.receiveData(data);
        }
      }
      buffer.clear();
    }
  }
};