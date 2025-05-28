# ret2shellcode Challenge

## Description

This is a classic binary exploitation challenge called **ret2shellcode**. 

Your goal is to inject shellcode into the program’s stack and redirect execution to it by exploiting a buffer overflow vulnerability.

Because NX is disabled and ASLR is disabled, you can reliably execute your shellcode on the stack.


## How to compile the binary

```bash
gcc -no-pie -z execstack -fno-stack-protector -o ret2shellcode ret2shellcode.c
```

## How to enable/disable ASLR on your system
**Disable ASLR (makes memory layout predictable):**
```bash
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
```

**Enable ASLR (default, makes memory layout random):**
```bash
echo 2 | sudo tee /proc/sys/kernel/randomize_va_space
```

You can check the current ASLR status with:
```bash
cat /proc/sys/kernel/randomize_va_space
```
- 0 means ASLR disabled
- 1 means partial randomization
- 2 means full randomization (default)