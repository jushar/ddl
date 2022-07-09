#include "ddl/fakes/FakeFlash.hpp"

#include <cstring>

namespace ddl {

FakeFlash::FakeFlash(std::size_t size) { memory_.resize(size); }

void FakeFlash::readPage(std::uint32_t address, std::byte* dest, std::size_t size) {
  std::memcpy(dest, memory_.data() + address, size);
}

void FakeFlash::writePage(std::uint32_t address, std::byte* data, std::size_t size) {
  // TODO: Only flip 1 -> 0
  std::memcpy(memory_.data() + address, data, size);
}

void FakeFlash::eraseSector(std::uint32_t address) {
  std::fill(memory_.begin() + address, memory_.begin() + address + kFlashSize, std::byte{0xff});
}

}  // namespace ddl
