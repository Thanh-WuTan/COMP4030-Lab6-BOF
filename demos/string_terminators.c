#include <stdio.h>
#include <string.h>

int main(){
    char name[10] = {0};
    read(0, name, sizeof(name));
    printf("Hello, %s\n", name);
}