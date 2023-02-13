#include <stdio.h>

int LastDigitOfTheSumOfSquaresOfFibonacciNumbers(long long n) {
    if (n <= 1) return n;
    long long sum = 0;
    long long prev = 0;
    long long cur = 1;
    for (long long i = 1; i <= n; i++) {
        long long tmp = prev;
        prev = cur;
        cur = (cur + tmp) % 10;
        sum = (sum + cur * cur) % 10;
    }
    return sum;
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%d", LastDigitOfTheSumOfSquaresOfFibonacciNumbers(n));
    return 0;
}
