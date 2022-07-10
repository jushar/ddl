#pragma once

#include "ddl/I2C.hpp"

namespace ddl {

class ST_I2C final : public I2C {
 public:
  ST_I2C(I2CConfig const& config);
};

}  // namespace ddl