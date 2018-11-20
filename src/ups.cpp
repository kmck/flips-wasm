#include "../Flips/libups.h"
#include <emscripten/bind.h>
#include <string.h>

using namespace emscripten;

struct mem stringToMem(std::string str) {
  uint8_t* data = (uint8_t*) str.c_str();
  return { data, str.length() };
}

val upsApply(std::string patch, std::string source) {
  struct mem target = { NULL, 0 };
  enum upserror err = ups_apply(stringToMem(patch), stringToMem(source), &target);
  if (err) {
    return val(err);
  }
  return val(typed_memory_view(target.len, target.ptr));
}

val upsCreate(std::string source, std::string target) {
  struct mem patch = { NULL, 0 };
  enum upserror err = ups_create(stringToMem(source), stringToMem(target), &patch);
  if (err) {
    return val(err);
  }
  return val(typed_memory_view(patch.len, patch.ptr));
}

EMSCRIPTEN_BINDINGS(flips_ups) {
  enum_<upserror>("upserror")
    .value("ups_ok", ups_ok)
    .value("ups_unused1", ups_unused1)
    .value("ups_not_this", ups_not_this)
    .value("ups_broken", ups_broken)
    .value("ups_unused2", ups_unused2)
    .value("ups_identical", ups_identical)
    .value("ups_too_big", ups_too_big)
    .value("ups_unused3", ups_unused3)
    .value("ups_unused4", ups_unused4)
    .value("ups_shut_up_gcc", ups_shut_up_gcc);

  function("upsApply", &upsApply);
  function("upsCreate", &upsCreate);
}
