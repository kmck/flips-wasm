import loadWasmModule from './wasm/ups';

const UPS = loadWasmModule();

export function upsApply(patch, source) {
  return UPS.upsApply(patch, source);
}

export function upsCreate(source, target) {
  return UPS.upsCreate(source, target);
}
