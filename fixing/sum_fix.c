#include <stdio.h>

int main() {
    int n = 5;
    int sum = 0; 

    // Goal: Calculate the sum of 1 + 2 + 3 + 4 + 5
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("The sum of numbers from 1 to %d is: %d\n", n, sum);
    printf("Expected: 15\n");

    return 0;
}
