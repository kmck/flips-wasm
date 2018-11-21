# Floating IPS in Wasm

This is a [WebAssembly] version of Alcaro's excellent [Floating IPS][Flips] created with
[Emscripten] for use in JavaScript projects.

## Installation

```bash
npm install flips-wasm
```

Or using Yarn:

```bash
yarn add flips-wasm
```

## Usage

In Node.js:

```js
const {
  bpsCreate,
  bpsApply,
  ipsCreate,
  ipsApply,
  upsCreate,
  upsApply,
} = require('flips-wasm');
```

In ES6:

```js
import {
  bpsCreate,
  bpsApply,
  ipsCreate,
  ipsApply,
  upsCreate,
  upsApply,
} from 'flips-wasm';
```

The Wasm modules are loaded asynchronously, so you may want to use the corresponding `Promise`
versions of the functions in your code. The Promise resolves with the result of the Flips function.

```js
import { bpsCreatePromise } from 'flips-wasm';

bpsCreatePromise(sourceFile, targetFile).then(patchFile => {
  // ...write to file
});
```

# Building

You probably don't need to build this, but I'll tell you how to anyway.

First, make sure you have [Emscripten] installed so you can use the `emcc` command.

```bash
npm run build
```

This will create various `js` and `wasm` files in the `lib/` directory.

## Acknowledgements

* Alcaro, author of [Flips]
* Surma, who wrote [this useful article](https://developers.google.com/web/updates/2018/03/emscripting-a-c-library)

[Flips]: https://github.com/Alcaro/Flips
[WebAssembly]: https://webassembly.org
[Emscripten]: http://kripken.github.io/emscripten-site
