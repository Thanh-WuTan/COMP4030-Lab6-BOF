section .data
    filename    db "/flag", 0      ; Null-terminated file path
    buf         times 256 db 0     ; 256-byte buffer for file content

section .text
    global _start

_start:
    ; open("/flag", O_RDONLY, 0)
    mov     rax, 2          ; syscall: sys_open
    lea     rdi, [rel filename]  ; const char *filename
    mov     rsi, 0          ; int flags = O_RDONLY
    mov     rdx, 0          ; mode (unused)
    syscall
    mov     r12, rax        ; store file descriptor

    ; read(fd, buf, 256)
    mov     rax, 0          ; syscall: sys_read
    mov     rdi, r12        ; file descriptor
    lea     rsi, [rel buf]  ; buffer
    mov     rdx, 256        ; size
    syscall
    mov     r13, rax        ; number of bytes read

    ; write(1, buf, bytes_read)
    mov     rax, 1          ; syscall: sys_write
    mov     rdi, 1          ; stdout
    lea     rsi, [rel buf]  ; buffer
    mov     rdx, r13        ; size
    syscall

    ; exit(0)
    mov     rax, 60         ; syscall: sys_exit
    xor     rdi, rdi        ; status = 0
    syscall

; To assemble and run:
; nasm -f elf64 -o print_flag.o print_flag.asm
; ld -o print_flag print_flag.o
