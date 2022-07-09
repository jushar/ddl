#include "ddl/drivers/LPS22DF.hpp"

namespace ddl {

LPS22DF::LPS22DF(I2C& i2c) : i2c_{i2c} {}

float LPS22DF::readValue(SensorChannel channel) { return 0; }

}  // namespace ddl
