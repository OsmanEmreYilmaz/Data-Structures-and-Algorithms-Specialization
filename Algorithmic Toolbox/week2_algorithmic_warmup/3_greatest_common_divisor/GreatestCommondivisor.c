#include <stdio.h>

size_t GreatestCommonDivisor(size_t a,size_t b){
    while(b != 0) {
        size_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    size_t a, b;
    scanf("%zu", &a);
    scanf("%zu", &b);
    printf("%zu", GreatestCommonDivisor(a, b));
    return 0;
}