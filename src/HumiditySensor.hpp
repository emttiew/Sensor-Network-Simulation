#pragma once
#include <iostream>
#include "Sensor.hpp"

namespace sensor {
struct HumiditySensorData : SensorData
{
    explicit HumiditySensorData(int pId) : SensorData(pId) {}
    void print() override
    {
        std::cout << "HumiditySensor sensor id: " << id << " with humidity: " << humidity << std::endl;
    }
    float humidity;
};

class HumiditySensor : public Sensor {
 public:
  HumiditySensor(int id, MainNode& mainNode) : Sensor(mainNode), sensorData(id) {}

 private:
 HumiditySensorData sensorData;
  void generateData() {
    sensorData.humidity = 11.1;
    mainNode.receiveData(std::make_shared<HumiditySensorData>(sensorData));
  }
};
}  // namespace sensor