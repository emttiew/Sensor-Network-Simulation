#include "Client.hpp"

#include "Sensor.hpp"

void Client::receiveData(sensor::SensorDataPtr const& dataPtr) {
  dataPtr->print();
}