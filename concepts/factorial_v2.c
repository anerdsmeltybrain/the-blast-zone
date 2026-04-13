#include <stdio.h>

// Function Declaration (Prototypes)
int factorial_iterative(int n);
int factorial_recursive(int n);

int main() {
    int number;

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    // Calling the iterative version
    printf("[Iterative] %d! = %d\n", number, factorial_iterative(number));

    // Calling the recursive version
    printf("[Recursive] %d! = %d\n", number, factorial_recursive(number));

    return 0;
}

/**
 * Iterative version: uses a 'while' or 'for' loop (similar to your original code).
 */
int factorial_iterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

/**
 * Recursive version: the function calls itself!
 * 5! = 5 * 4!
 * 4! = 4 * 3!
 * ... until it hits the 'Base Case' (1! = 1)
 */
int factorial_recursive(int n) {
    // 1. Base Case: stops the recursion
    if (n <= 1) {
        return 1;
    }
    // 2. Recursive Step: calls itself with (n - 1)
    return n * factorial_recursive(n - 1);
}
