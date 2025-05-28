#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

void __attribute__((noinline)) win() {
    char flag[256];
    int fd = open("/flag", O_RDONLY);
    if (fd < 0) {
        perror("Failed to open /flag");
        exit(1);
    }

    int len = read(fd, flag, sizeof(flag));
    if (len <= 0) {
        perror("Failed to read flag");
        exit(1);
    }

    write(STDOUT_FILENO, flag, len);
    puts("");
}

int challenge() {
    struct {
        char input[72];
        int trigger;
    } data = {0};

    puts("Send your payload:");
    ssize_t r = read(STDIN_FILENO, data.input, sizeof(data));
    if (r < 0) {
        perror("Read failed");
        exit(1);
    }

    if (data.trigger)
        win();

    puts("Goodbye!");
    return 0;
}

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    char crash_resistance[0x1000]; // dummy space
    challenge();
    return 0;
}
