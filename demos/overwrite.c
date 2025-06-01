#include <stdio.h>
#include <string.h>

// Vulnerable function demonstrating buffer overflow
void vulnerable() {
    char buffer[8]; // Small buffer of 8 bytes
    int x = 10;     // Local variable on the stack
    printf("Before input: x = %d\n", x);
    printf("Enter text: ");
    gets(buffer);   // Unsafe: No bounds checking, can overflow!
    printf("After input: x = %d\n", x);
    printf("Buffer content: %s\n", buffer);
}

int main() {
    printf("Starting the program...\n");
    vulnerable(); 
    printf("Program finished normally.\n");
    return 0;
}

// To compile this code, use:
// gcc -fno-stack-protector overwrite.c -o a.out
// To run the program, use:
// ./a.out