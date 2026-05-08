#include <stdio.h>

// Goal: Find the index of 'target' in a sorted array using recursion.
// Returns -1 if not found.
int binary_search(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] > target) {
        // Bug: Look closely at the boundaries being passed
        return binary_search(arr, low, mid - 1, target); 
    } else {
        // Bug: Look closely at the boundaries being passed
        return binary_search(arr, mid + 1, high, target);
    }
}

int main() {
    int nums[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = 10;
    int target = 23;

    int result = binary_search(nums, 0, n - 1, target);

    if (result != -1) {
        printf("Found %d at index %d\n", target, result);
    } else {
        printf("%d not found in the array\n", target);
    }
    
    printf("Expected: Found 23 at index 5\n");

    return 0;
}
