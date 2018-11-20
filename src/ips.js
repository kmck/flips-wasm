import loadWasmModule from './wasm/ips';

const IPS = loadWasmModule();

export function ipsApply(patch, source) {
  return IPS.ipsApply(patch, source);
}

export function ipsCreate(source, target) {
  return IPS.ipsCreate(source, target);
}
