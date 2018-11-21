import loadWasmModule from './wasm/ips';
import { whenModuleReady } from './utils';

const wasmModule = loadWasmModule();

export function ipsApply(patch, source) {
  return wasmModule.ipsApply(patch, source);
}

export function ipsCreate(source, target) {
  return wasmModule.ipsCreate(source, target);
}

export const ipsApplyPromise = whenModuleReady(wasmModule, ipsApply);
export const ipsCreatePromise = whenModuleReady(wasmModule, ipsCreate);
