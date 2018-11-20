import loadWasmModule from './wasm/bps';

const BPS = loadWasmModule();

export function bpsApply(patch, source, acceptWrongInput = false) {
  return BPS.bpsApply(patch, source, acceptWrongInput);
}

export function bpsCreateLinear(source, target) {
  return BPS.bpsCreateLinear(source, target);
}

export const bpsCreate = bpsCreateLinear;
