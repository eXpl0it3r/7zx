7zx
===

7zx is a small C library to extract, test and list 7z / 7zip archives.
It's a thin wrapper around the 7z decoder of the [LZMA SDK](https://www.7-zip.org/sdk.html), currently version 26.03.

Supported Methods
-----------------

- Compression: LZMA, LZMA2, PPMd and Copy (i.e. stored)
- Filters: BCJ (x86), BCJ2, ARM64, ARM, ARMT, PPC, IA64, SPARC, RISCV and Delta

Note that encrypted archives (AES) and archives using other methods like BZip2 or Deflate aren't supported by the decoder and return `SZ_ERROR_UNSUPPORTED`.

Usage
-----

```c
char list[1024] = {};
size_t size = 1024;
SzxList("example.7z", list, &size); // List the archive's content
SzxTest("example.7z");              // Test the archive
SzxExtract("example.7z");           // Extract the archive with full paths
SzxExtract("example.7z", 0);        // Extract the archive flat
```

The default argument for `SzxExtract` only exists in C++, in C you have to pass `1` to extract with full paths.

`SzxList` writes one line per entry into the buffer, with the modification time, the attributes, the size and the path separated by tabs.

License
-------

7zx is released into the public domain under the [Unlicense](LICENSE).

It's heavily based on the source code of the LZMA SDK, which Igor Pavlov has placed in the public domain as well.
The files in `src` other than `7zx.c`, as well as `include/7zx/7zTypes.h`, are taken unmodified from the LZMA SDK, and `7zx.c` is derived from its `Util/7z/7zMain.c`.

> LZMA SDK is written and placed in the public domain by Igor Pavlov.
>
> Some code in LZMA SDK is based on public domain code from another developers:
> 1) PPMd var.H (2001): Dmitry Shkarin
> 2) SHA-256: Wei Dai (Crypto++ library)
>
> Anyone is free to copy, modify, publish, use, compile, sell, or distribute the
> original LZMA SDK code, either in source code form or as a compiled binary, for
> any purpose, commercial or non-commercial, and by any means.
