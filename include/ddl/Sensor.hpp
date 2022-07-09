#pragma once

namespace ddl {

enum class SensorChannel {
  Default,

  Channel1,
  Channel2,
  Channel3,
  Channel4,
  Channel5,
  Channel6,

  AxisX,
  AxisY,
  AxisZ,
};

class Sensor {
 public:
  virtual ~Sensor() = default;

  virtual float readValue(SensorChannel channel) = 0;
};

}  // namespace ddl
