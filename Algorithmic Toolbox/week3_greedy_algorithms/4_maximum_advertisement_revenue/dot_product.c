#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

long long max_dot_product(int a[], int b[], int n) {
    long long res = 0;
    qsort(a, n, sizeof(int), cmpfunc);
    qsort(b, n, sizeof(int), cmpfunc);
    for (int i = 0; i < n; i++) {
        res += a[i] * b[i];
    }
    return res;
}

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n], b[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    printf("%lld\n", max_dot_product(a, b, n));
    return 0;
}
