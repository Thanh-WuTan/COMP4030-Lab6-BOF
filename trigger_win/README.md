# trigger_win

## Challenge Overview

This is a beginner-friendly binary exploitation challenge designed to teach:

- Stack-based buffer overflows
- How to overwrite adjacent variables on the stack
- Basic use of `gdb`, `pwndbg`, or `pwntools`

## Goal

Your objective is to trigger the hidden `win()` function by sending a carefully crafted input that sets the `trigger` variable to a non-zero value.

If successful, the binary will reveal the contents of `/flag`.

## Compilation

If you want to rebuild it:

```bash
gcc -no-pie -Wl,-z,relro,-z,now -o trigger_win trigger_win.c
```