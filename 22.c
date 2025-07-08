#include <stdio.h>
#include <stdlib.h>

int* product(int* num, int numsize, int* returnsize) {
    int* result = (int*)malloc(numsize * sizeof(int));
    *returnsize = numsize;

    
    for (int i = 0; i < numsize; i++) {// initializing the result array with 1
        result[i] = 1;
    }

   
    int prefix = 1; //prefix products
    for (int i = 0; i < numsize; i++) {
        result[i] = prefix;
        prefix *= num[i];
    }

   
    int suffix = 1; //suffix products
    for (int i = numsize - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= num[i];
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int returnsize;
    int* result = product(nums, n, &returnsize);

    for (int i = 0; i < returnsize; i++) {
        printf("%d ", result[i]); //print the product of array 
    }
    printf("\n"); 

    free(nums);
    free(result);

    return 0;
}