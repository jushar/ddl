#pragma once

#include "ddl/I2C.hpp"
#include "ddl/Sensor.hpp"

namespace ddl {

class LPS22DF : public Sensor {
 public:
  explicit LPS22DF(I2C& i2c);

  float readValue(SensorChannel channel) override;

 private:
  I2C& i2c_;
};

}  // namespace ddl
