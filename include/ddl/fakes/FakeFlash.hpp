#pragma once

#include <vector>

#include "ddl/Flash.hpp"

namespace ddl {

class FakeFlash : public Flash {
 public:
  explicit FakeFlash(std::size_t size);

  void readPage(std::uint32_t address, std::byte* dest, std::size_t size) override;

  void writePage(std::uint32_t address, std::byte* data, std::size_t size) override;

  void eraseSector(std::uint32_t address) override;

 private:
  std::vector<std::byte> memory_;

  static constexpr std::size_t kFlashSize{4096u};
};

}  // namespace ddl
