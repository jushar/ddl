#include <iostream>
#include <cassert>

#include "ddl/Sensor.hpp"
#include "ddl/fakes/FakeSensor.hpp"

// The Feature implementation is independent of any
// hardware details.
class MotionDetector {
 public:
  explicit MotionDetector(ddl::Sensor& motionSensor) : motionSensor_{motionSensor} {}

  bool detectMotion() {
    return motionSensor_.readValue(ddl::SensorChannel::AxisX) > kMotionThreshold ||
           motionSensor_.readValue(ddl::SensorChannel::AxisY) > kMotionThreshold ||
           motionSensor_.readValue(ddl::SensorChannel::AxisZ) > kMotionThreshold;
  }

 private:
  ddl::Sensor& motionSensor_;
  static constexpr float kMotionThreshold{0.5f};
};

int main() {
  // Bootstrap feature with fake sensor
  ddl::FakeSensor motionSensor{};
  MotionDetector motionDetector{motionSensor};

  // A unit test would then assert and simulate sensor values
  assert(motionDetector.detectMotion() == false);
  motionSensor.simulateValue(ddl::SensorChannel::AxisX, 50.0f);
  assert(motionDetector.detectMotion() == true);
  std::cout << "All tests passed!\n";
}
