#include <thread>

#include "Sensor.hpp"

void MainNode::receiveData(sensor::SensorDataPtr dataPtr) {
  std::lock_guard<std::mutex> lock(mutex);

  buffer.push_back(dataPtr);

  // Notify clients if it's time
  auto now = std::chrono::system_clock::now();
  if (now - lastNotificationTime >= std::chrono::seconds(1)) {
    condVar.notify_one();
    lastNotificationTime = now;
  }
}

void MainNode::start() {
  std::thread notifyThread(&MainNode::notifyClients, this);
  notifyThread.detach();
}

void MainNode::notifyClients() {
  while (true) {
    std::unique_lock<std::mutex> lock(mutex);

    condVar.wait(lock);

    for (sensor::SensorDataPtr const& data : buffer) {
      int clientId = 0;
      for (Client& client : clients) {
        client.receiveData(data, clientId++);
      }
    }
    buffer.clear();
  }
}