#include "utils.h"

#include <sstream>
#include <windows.h>

#include <infoware/infoware.hpp>
#include <data_representation/data_representation.h>

std::string utils::hwid() {
  std::stringstream stream;

  stream << iware::system::OS_info().full_name.c_str();
  stream << iware::cpu::model_name().c_str();
  stream << iware::system::memory().physical_total;

  for (const auto& gpu : iware::gpu::device_properties()) {
    stream << gpu.name.c_str();
    stream << gpu.memory_size;
  }

  return data_representation::sha256_string(stream.str().c_str());
}

bool utils::memory::compare_data(uint8_t* data, const char* bytes, const char* mask) {
  size_t size = strlen(mask);

  for (size_t i = 0; i < size; ++i)
    if (mask[i] != '?' && data[i] != static_cast<uint8_t>(bytes[i])) return false;

  return true;
}

uintptr_t utils::memory::find_pattern(const char* name, const char* bytes, const char* mask) {
  uintptr_t mod_base = reinterpret_cast<uintptr_t>(GetModuleHandleA(name));

  if (mod_base == 0) return 0;

  auto* opt =
      &reinterpret_cast<IMAGE_NT_HEADERS*>(mod_base +
                                           reinterpret_cast<IMAGE_DOS_HEADER*>(mod_base)->e_lfanew)
           ->OptionalHeader;

  for (uintptr_t address = mod_base; address < mod_base + opt->SizeOfImage - 1; address++)
    if (compare_data(reinterpret_cast<uint8_t*>(address), bytes, mask)) return address;

  return 0;
}
