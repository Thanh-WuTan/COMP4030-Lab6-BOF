#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void vuln() {
    char buffer[128];

    puts("Welcome to ret2shellcode challenge!");
    puts("Send your payload:");
    read(0, buffer, 512); // buffer overflow
} 

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);   // Disable input buffering
    setvbuf(stdout, NULL, _IONBF, 0);  // Disable output buffering

    vuln();

    puts("Goodbye!");
    return 0;
}
