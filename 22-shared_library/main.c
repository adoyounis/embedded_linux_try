// main.c
#include "factorial.h"

int main() {
    int num = 5;
    int result;


    result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}
