#pragma once

#include <iostream>

#include "Sensor.hpp"

namespace sensor {

struct TemperatureSensorData : SensorData {
  explicit TemperatureSensorData(int pId) : SensorData(pId) {}
  void print() override {
    std::cout << "Temperature sensor id: " << id
              << " with temperature: " << temperature << std::endl;
  }
  float temperature;
};

class TemperatureSensor : public Sensor {
 public:
  TemperatureSensor(int id, MainNode& mainNode)
      : Sensor(mainNode), sensorData(id) {}

 private:
  TemperatureSensorData sensorData;
  void generateData() {
    while (true) {
      sensorData.temperature = rand() % 100;
      mainNode.receiveData(std::make_shared<TemperatureSensorData>(sensorData));
    }
  }
};
}  // namespace sensor