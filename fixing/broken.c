#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    float average;

    // Calculate average
    average = (a + b) / 2;

    printf("The average of %d and %d is: %f\n", a, b, average);

    if (a == 10) {
        printf("A is ten!\n");
    }

    return 0;
}
