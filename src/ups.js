import loadWasmModule from './wasm/ups';
import { whenModuleReady } from './utils';

const wasmModule = loadWasmModule();

export function upsApply(patch, source) {
  return wasmModule.upsApply(patch, source);
}

export function upsCreate(source, target) {
  return wasmModule.upsCreate(source, target);
}

export const upsApplyPromise = whenModuleReady(wasmModule, upsApply);
export const upsCreatePromise = whenModuleReady(wasmModule, upsCreate);
