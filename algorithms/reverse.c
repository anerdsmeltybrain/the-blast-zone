#include <stdio.h>

void reverse_array(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    // YOUR TASK:
    // Use a while loop to swap the elements at 'left' and 'right'
    // then move 'left' forward and 'right' backward.
    // Remember: you need a 'temp' variable to swap two numbers!

    while (left < right) {
        // [Add swap logic here]

        left++;
        right--;
    }
}

int main() {
    int numbers[5];

    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Call the reversal function
    reverse_array(numbers, 5);

    printf("\nReversed array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
