7zx
===

7zx is a small C library to extract, test and list 7z / 7zip archives.
Supported formats are LZMA, LZMA2 and PPMD.

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
