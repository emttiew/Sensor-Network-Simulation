#pragma once

#include "Sensor.hpp"

namespace sensor {

class HumiditySensor : public Sensor {
 public:
  HumiditySensor(int id, MainNode& mainNode) : Sensor(id, mainNode) {}
  void setTemperature(float pHumidity) { humidity = pHumidity; }

 private:
  float humidity;
  void generateData() {
    humidity = 10;
    mainNode.receiveData(humidity);
  }
};
}  // namespace sensor