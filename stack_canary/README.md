# stack_canary

## Description

This is a buffer overflow challenge with stack canary protection enabled.

Your goal is to overflow the local buffer in the `challenge()` function and bypass the stack canary to control execution flow.

There is also a hidden backdoor that allows the `challenge()` function to be called more than once. Use GDB to discover it.

## Build

```bash
gcc -m64 -fstack-protector -pie -fPIE -fno-stack-check -o chall stack_canary.c
```