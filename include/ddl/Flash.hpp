#pragma once

#include <cstddef>
#include <cstdint>

namespace ddl {

class Flash {
 public:
  virtual ~Flash() = default;

  virtual void readPage(std::uint32_t address, std::byte* dest, std::size_t size) = 0;

  virtual void writePage(std::uint32_t address, std::byte* data, std::size_t size) = 0;

  virtual void eraseSector(std::uint32_t address) = 0;
};

}  // namespace ddl
