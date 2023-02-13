#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    char s1[1000], s2[1000];
    sprintf(s1, "%d%d", *(int*)b, *(int*)a);
    sprintf(s2, "%d%d", *(int*)a, *(int*)b);
    return strcmp(s1, s2);
}

int main() {
    int n, i;
    scanf("%d", &n);
    int numbers[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    qsort(numbers, n, sizeof(int), cmp);
    for (i = 0; i < n; i++) {
        printf("%d", numbers[i]);
    }
    return 0;
}
