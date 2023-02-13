#include <stdio.h>

long long fibonacci(long long n)
{
    if (n <= 1)
        return n;

    long long prev = 0;
    long long cur = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp = prev;
        prev = cur;
        cur = tmp + cur;
    }

    return cur;
}

int main(){
    long long n;
    scanf("%lld", &n);
    printf("%lld", fibonacci(n));
}