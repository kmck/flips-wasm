#include "../Flips/libips.h"
#include <emscripten/bind.h>
#include <string.h>

using namespace emscripten;

struct mem stringToMem(std::string str) {
  uint8_t* data = (uint8_t*) str.c_str();
  return { data, str.length() };
}

val ipsApply(std::string patch, std::string source) {
  struct mem target = { NULL, 0 };
  enum ipserror err = ips_apply(stringToMem(patch), stringToMem(source), &target);
  if (err) {
    return val(err);
  }
  return val(typed_memory_view(target.len, target.ptr));
}

val ipsCreate(std::string source, std::string target) {
  struct mem patch = { NULL, 0 };
  enum ipserror err = ips_create(stringToMem(source), stringToMem(target), &patch);
  if (err) {
    return val(err);
  }
  return val(typed_memory_view(patch.len, patch.ptr));
}

EMSCRIPTEN_BINDINGS(flips_ips) {
  enum_<ipserror>("ipserror")
    .value("ips_ok", ips_ok)
    .value("ips_notthis", ips_notthis)
    .value("ips_thisout", ips_thisout)
    .value("ips_scrambled", ips_scrambled)
    .value("ips_invalid", ips_invalid)
    .value("ips_16MB", ips_16MB)
    .value("ips_identical", ips_identical)
    .value("ips_shut_up_gcc", ips_shut_up_gcc);

  function("ipsApply", &ipsApply);
  function("ipsCreate", &ipsCreate);
}
