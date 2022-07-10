#include <iostream>

#include "ddl/fakes/FakeSensor.hpp"

template<typename Sensor>
// Prototype with `bool myFeature(ddl::Sensor& sensor)` to get auto-completion
// then replace with template type
bool myFeature(Sensor& sensor) {
  return sensor.readValue(ddl::SensorChannel::Default) > 0.0f;
}

int main() {
  ddl::FakeSensor sensor{};
  std::cout << myFeature(sensor);
}