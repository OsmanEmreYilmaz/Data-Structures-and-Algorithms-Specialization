#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t maxpairwise(size_t *a,int n)
{
    size_t max1 = 0;
    size_t max2 = 0;
    for(int i =0;i<n;i++)
    {
        if(a[i]>max1){
            max2 = max1;
            max1=a[i];
        }
        else if(a[i]>max2)
            max2=a[i];
    }
    return max1 * max2;
}

int main(){
    int n;
    scanf("%d",&n);
    size_t *nums = malloc(sizeof(size_t)*n);
    for(int i=0;i<n;i++)
    {
        size_t a;
        scanf("%zu",&a);
        nums[i] = a;
    }
    /*for(int i=0;i<n;i++)
    {
        printf("%d",nums[i]);
    }*/
    printf("%zu",maxpairwise(nums,n));
    free(nums);
    return (0);
}