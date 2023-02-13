#include <stdio.h>

long long fibonacciNumber(long long n, long long m) {
    if (n <= 1) return n;

    long long prev = 0;
    long long cur = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp = prev % m;
        prev = cur % m;
        cur = (tmp + cur) % m;
    }

    return cur;
}

int main() {
    long long n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    printf("%lld", fibonacciNumber(n, m));
    return 0;
}
