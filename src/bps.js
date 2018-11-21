import loadWasmModule from './wasm/bps';
import { whenModuleReady } from './utils';

export const wasmModule = loadWasmModule();

export function bpsApply(patch, source, acceptWrongInput = false) {
  return wasmModule.bpsApply(patch, source, acceptWrongInput);
}

export function bpsCreateLinear(source, target) {
  return wasmModule.bpsCreateLinear(source, target);
}

export const bpsCreate = bpsCreateLinear;

export const bpsApplyPromise = whenModuleReady(wasmModule, bpsApply);
export const bpsCreateLinearPromise = whenModuleReady(wasmModule, bpsCreateLinear);
export const bpsCreatePromise = whenModuleReady(wasmModule, bpsCreate);
