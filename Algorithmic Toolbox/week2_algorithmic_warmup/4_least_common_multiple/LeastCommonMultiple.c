#include <stdio.h>
#include <stdlib.h>

size_t GreatestCommonDivisor(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

size_t LeastCommonMultiple(int a, int b) {
    return (a / GreatestCommonDivisor(a, b)) * b;
}

int main() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%zu", LeastCommonMultiple(a, b));
    return 0;
}
