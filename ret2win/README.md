# ret2win

## Description

This is a simple buffer overflow challenge focused on controlling the return address to gain code execution.

Your goal is to overflow the local buffer in the `challenge()` function and overwrite the return address to jump to the `win()` function.

If successful, `win()` will print the flag located at `/flag`.

## Build

```bash
gcc -o chall ret2win.c -fno-stack-protector -no-pie
```