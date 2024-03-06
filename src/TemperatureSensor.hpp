#pragma once

#include "Sensor.hpp"

namespace sensor {

class TemperatureSensor : public Sensor {
 public:
  TemperatureSensor(int id, MainNode& mainNode) : Sensor(id, mainNode) {}
  void setTemperature(float temp) { temperature = temp; }

 private:
  float temperature;
  void generateData() {
    temperature = 20.5;
    mainNode.receiveData(temperature);
  }
};
}  // namespace sensor