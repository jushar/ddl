#pragma once

#include <cstdint>

namespace ddl {

struct I2CConfig {
  std::uint32_t address;
};

class I2C {
 public:
  virtual ~I2C() = default;
};

}  // namespace ddl