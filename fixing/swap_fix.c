#include <stdio.h>

// Goal: Swap the values of two integers using a function
void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    printf("Before swap: x = %d, y = %d\n", x, y);

    // This call won't work as expected!
    swap(&x, &y);

    printf("After swap:  x = %d, y = %d\n", x, y);
    printf("Expected:    x = 20, y = 10\n");

    return 0;
}
