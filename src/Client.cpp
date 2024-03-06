#include "Client.hpp"

#include "Sensor.hpp"

void Client::receiveData(sensor::SensorDataPtr const& dataPtr, int id) {
  std::cout << "Client ID: " << id << " received -> "; 
  dataPtr->print();
}