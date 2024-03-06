#pragma once

#include <memory>

namespace sensor {
struct SensorData;
class Sensor;
using SensorDataPtr = std::shared_ptr<SensorData>;
using SensorPtr = std::shared_ptr<Sensor>;
}