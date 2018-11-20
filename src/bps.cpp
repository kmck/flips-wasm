#include "../Flips/libbps.h"
#include <emscripten/bind.h>
#include <string.h>

using namespace emscripten;

struct mem stringToMem(std::string str) {
  uint8_t* data = (uint8_t*) str.c_str();
  return { data, str.length() };
}

val bpsApply(std::string patch, std::string source, bool acceptWrongInput) {
  struct mem target = { NULL, 0 };
  enum bpserror err = bps_apply(stringToMem(patch), stringToMem(source), &target, NULL, acceptWrongInput);
  if (err && (err != bps_not_this || !acceptWrongInput)) {
    return val(err);
  }
  return val(typed_memory_view(target.len, target.ptr));
}

val bpsCreateLinear(std::string source, std::string target) {
  struct mem patch = { NULL, 0 };
  struct mem manifest = { NULL, 0 };
  enum bpserror err = bps_create_linear(stringToMem(source), stringToMem(target), manifest, &patch);
  if (err) {
    return val(err);
  }
  return val(typed_memory_view(patch.len, patch.ptr));
}

EMSCRIPTEN_BINDINGS(flips_bps) {
  enum_<bpserror>("bpserror")
    .value("bps_ok", bps_ok)
    .value("bps_to_output", bps_to_output)
    .value("bps_not_this", bps_not_this)
    .value("bps_broken", bps_broken)
    .value("bps_io", bps_io)
    .value("bps_identical", bps_identical)
    .value("bps_too_big", bps_too_big)
    .value("bps_out_of_mem", bps_out_of_mem)
    .value("bps_canceled", bps_canceled)
    .value("bps_shut_up_gcc", bps_shut_up_gcc);

  function("bpsApply", &bpsApply);
  function("bpsCreateLinear", &bpsCreateLinear);
}
