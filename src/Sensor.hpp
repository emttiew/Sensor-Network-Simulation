#pragma once

#include <memory>
#include <thread>

#include "MainNode.hpp"

namespace sensor {

class Sensor {
 public:
  Sensor(int id, MainNode& mainNode) : id(id), mainNode(mainNode) {}
  void start() {
    std::thread dataThread(&Sensor::generateData, this);
    dataThread.detach();
  }
  virtual ~Sensor() {}

 protected:
  virtual void generateData() = 0;

 protected:
  int id;
  MainNode& mainNode;
};

using SensorPtr = std::shared_ptr<Sensor>;
}  // namespace sensor