# libc_mini

Minimal libc-style helpers and Linux syscall wrappers in C, plus tiny HTTP server examples for exercising the APIs.

## What’s inside
- String/memory/stdio-like helpers (`include/e_lib.h`, `src/stdio/`)
- Direct syscall wrappers (`include/syscall.h`, `src/syscalls/`)
- Example servers (`servers/`) that use the library

## Build
```sh
make
```

Build artifacts are written to `build/`.

## Run examples
```sh
./build/server
```

The example server listens on port 4444 (hardcoded) and serves GET/POST requests using the minimal APIs.

## Notes
- Linux x86_64 only (inline `syscall` ABI)
- Not a full libc; intended for learning and experimentation

## Acknowledgments
* This project includes include/lwlog.h from lwlog, which is licensed under the MIT License. Copyright (c) 2021 Bob Liu.