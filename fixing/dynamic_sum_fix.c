#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5; 

    // Goal: Allocate memory for 5 integers, fill them with 1-5, and sum them.
    // Expected Sum: 15
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        return 1;
    }

    // Fill array with 1, 2, 3, 4, 5
    for (int i = 1; i <= n; i++) {
        arr[i - 1] = i; 
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum: %d\n", sum);
    printf("Expected Sum: 15\n");

    // Note: There are 3 main issues here:
    // 1. Array indexing (out of bounds)
    // 2. Summing logic (out of bounds)
    // 3. A missing important step for memory management

    free(arr);

    return 0;
}
