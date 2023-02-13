#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int x = *((int*)a);
    int y = *((int*)b);
    if (x < y) {
        return -1;
    } else if (x > y) {
        return 1;
    } else {
        return 0;
    }
}

int solve(int* a, int* b, int n) {
    qsort(a, n, sizeof(int), compare);
    qsort(b, n, sizeof(int), compare);
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i] * b[i];
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    int res = solve(a, b, n);
    printf("%d", res);
    return 0;
}
