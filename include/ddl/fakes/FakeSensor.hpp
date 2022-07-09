#pragma once

#include <unordered_map>

#include "ddl/Sensor.hpp"

namespace ddl {

class FakeSensor : public Sensor {
 public:
  float readValue(SensorChannel channel) override;

  void simulateValue(SensorChannel channel, float value);

 private:
  std::unordered_map<SensorChannel, float> values_;
};

}  // namespace ddl
