#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t maximum_pairwise(size_t *a, size_t n)
{
    size_t max1 = 0;
    size_t max2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        }
        else if (a[i] > max2) {
            max2 = a[i];
        }
    }
    return max1 * max2;
}


int main()
{
    size_t n;
    if (scanf("%zu", &n) != 1) {
        return 1;
    }
    size_t *nums = malloc(sizeof(size_t) * n);
    if (nums == NULL) {
        return 1;
    }
    for(int i=0;i<n;++i)
    {
        size_t a;
        if (scanf("%zu", &a) != 1) {
            free(nums);
            return 1;
        }
        nums[i] = a;
        
    }
    printf("%zu",maximum_pairwise(nums,n));
    free(nums);
    return 0;
}