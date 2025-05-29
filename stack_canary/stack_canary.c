#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void win_authed(int token) {
    if (token != 0xdeadbeef) {
        puts("Access denied!");
        exit(1);
    }
    system("cat /flag");
    exit(0);
}

long challenge(unsigned int argc, long argv, long envp) {
  char input[114] = {0};
  size_t len;
  printf("Payload size: ");
  if (scanf("%lu", &len) != 1) exit(1);

  printf("You have chosen to send %lu bytes of input!\n", len);
  void *buf = input;
  int n = read(0, buf, len);
  if (n < 0) {
    perror("ERROR: Failed to read input");
    exit(1);
  }

  printf("You sent %d bytes!\n", n);
  printf("You said: %s\n", (char *)buf);
  
  if (strstr((char *)buf, "REPEAT")) {
    puts("Backdoor triggered! Repeating challenge()");
    return challenge(argc, argv, envp);
  }

  puts("Goodbye!");
  return 0;
}

int main(int argc, const char **argv, const char **envp) {
  setvbuf(stdin, 0, _IOLBF, 0);
  setvbuf(stdout, 0, _IOLBF, 0);
  challenge(argc, (long)argv, (long)envp);
  return 0;
}