#pragma once

#include <iostream>

#include "SensorFwd.hpp"

class Client {
 public:
  Client(int id) : id(id) {}

  void receiveData(sensor::SensorDataPtr const& dataPtr, int id);

 private:
  int id;
};