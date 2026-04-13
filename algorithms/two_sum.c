#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int * ret = NULL;
    // Your implementation here
    for(int i = 0; i < numsSize; i++) {
       for(int j = i + 1; j < numsSize; j++) {
           if(nums[i] + nums[j] == target) {
                ret = realloc(ret,2 * sizeof (int));
                ret[0] = nums[i];
                ret[1] = nums[j];
                break;
           }
       } 
    }
    *returnSize = 2;
    return ret;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = 4;
    int returnSize;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL && returnSize == 2) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
