#pragma once

#include <memory>
#include <thread>

#include "MainNode.hpp"
#include "SensorFwd.hpp"

namespace sensor {

struct SensorData
{
    explicit SensorData(int pId) : id(pId) {}
    virtual void print() = 0;
    int id;
    virtual ~SensorData() {}
};

class Sensor {
 public:
  explicit Sensor(MainNode& mainNode) : mainNode(mainNode) {}
  void start() {
    std::thread dataThread(&Sensor::generateData, this);
    dataThread.detach();
  }
  virtual ~Sensor() {}

 protected:
  virtual void generateData() = 0;

 protected:
  SensorDataPtr dataPtr;
  MainNode& mainNode;
};
}  // namespace sensor