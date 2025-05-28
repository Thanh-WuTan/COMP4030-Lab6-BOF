# pie_overflow

## Description

This is a simple stack buffer overflow challenge with PIE enabled.

Your goal is to overflow the 64-byte buffer in `vuln()` and overwrite the return address to jump to `win_authed()` with the correct token `0xdeadbeef`.

If successful, `win_authed()` will print the flag located at `/flag`.

## Build

```bash
gcc pie_overflow.c -o chall -fno-stack-protector -z noexecstack -pie
```

## Hint
If you can control the return address, you can jump to whatever function you want (in case knowing PIE).