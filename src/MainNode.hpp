#pragma once

#include <boost/circular_buffer.hpp>
#include <condition_variable>
#include <mutex>
#include <vector>

#include "Client.hpp"
#include "SensorFwd.hpp"

class MainNode {
 public:
  explicit MainNode(int bufferSize) : buffer(bufferSize) {}

  void receiveData(sensor::SensorDataPtr dataPtr);

  void start();

  void addClient(Client& client) { clients.push_back(client); }

private:
  void notifyClients();

 private:
  boost::circular_buffer<sensor::SensorDataPtr> buffer;
  std::mutex mutex;
  std::condition_variable condVar;
  std::vector<std::reference_wrapper<Client>> clients;
  std::chrono::system_clock::time_point lastNotificationTime;

};