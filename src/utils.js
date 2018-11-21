export function whenModuleReady(wasmModule, fn) {
  return (...args) => new Promise((resolve, reject) => wasmModule.then(() => {
    const result = typeof fn === 'function'
      ? fn(...args)
      : module[fn](...args);
    resolve(result);
  }, reject));
}
