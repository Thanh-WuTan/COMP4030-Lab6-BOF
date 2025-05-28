#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void win() {
    char flag[256];
    int fd = open("/flag", O_RDONLY);
    if (fd < 0) exit(1);
    int len = read(fd, flag, sizeof(flag));
    if (len <= 0) exit(1);
    write(1, flag, len);
}

int challenge() {
    char buffer[104];
    read(0, buffer, 4096);
    return 0;
}

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    challenge();
}
