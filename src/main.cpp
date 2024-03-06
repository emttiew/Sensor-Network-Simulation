#include <cstdlib>
#include <vector>

#include "Client.hpp"
#include "HumiditySensor.hpp"
#include "Sensor.hpp"
#include "TemperatureSensor.hpp"

int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cerr << "Usage: " << argv[0]
              << " <client_size> <buffer_size> <sensor_size>\n";
    return 1;
  }

  int clientSize = std::atoi(argv[1]);
  int bufferSize = std::atoi(argv[2]);
  int sensorSize = std::atoi(argv[3]);

  MainNode mainNode(bufferSize);

  std::vector<sensor::SensorPtr> sensors;
  for (int i = 0; i < sensorSize; ++i) {
    sensors.push_back(std::make_shared<sensor::TemperatureSensor>(i, mainNode));
  }

  for (int i = 0; i < sensorSize; ++i) {
    sensors.push_back(std::make_shared<sensor::HumiditySensor>(i, mainNode));
  }

  for (sensor::SensorPtr const& sensor : sensors) {
    // start generating sensor data with a little delay to see how MainNode
    // gathers the data
    std::this_thread::sleep_for(std::chrono::seconds(1));
    sensor->start();
  }

  std::vector<Client> clients;
  for (int i = 0; i < clientSize; ++i) {
    clients.push_back(Client(i));
  }

  for (Client& client : clients) {
    mainNode.addClient(client);
  }

  mainNode.notifyClients();

  return 0;
}