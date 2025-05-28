#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
 
void win_authed(int token) {
    if (token != 0xdeadbeef) {
        puts("Access denied!");
        exit(1);
    }
    system("cat /flag");
    exit(0);
}

// Vulnerable function
void vuln() {
    char buf[64];
    puts("Welcome to PIE Challenge!");
    puts("Enter your input:");
    read(0, buf, 256); // stack overflow vulnerability
}

// Entry point
int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    setbuf(stderr, NULL);
    vuln();
    return 0;
}
