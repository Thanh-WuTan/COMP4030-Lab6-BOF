#include <stdio.h>


int mysum(int a, int b, int c) {
    return a + b + c;
}

int main(){
    int a = 1, b = 2, c = 3;
    int result = mysum(a, b, c);
    printf("SUM = %d\n", result);
    return 0;
}