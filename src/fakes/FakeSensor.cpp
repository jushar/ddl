#include "ddl/fakes/FakeSensor.hpp"

namespace ddl {

float FakeSensor::readValue(SensorChannel channel) { return values_[channel]; }

void FakeSensor::simulateValue(SensorChannel channel, float value) { values_[channel] = value; }

}  // namespace ddl
