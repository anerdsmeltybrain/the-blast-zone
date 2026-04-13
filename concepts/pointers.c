#include <stdio.h>

void square_by_value(int n);
void square_by_pointer(int *p_n);

int main() {
    int x = 5;
    int *ptr = &x; // 'ptr' now holds the address of 'x'

    printf("--- Variable Details ---\n");
    printf("Value of x: %d\n", x);
    printf("Address of x (&x): %p\n", (void*)&x);
    printf("Value stored in ptr: %p\n", (void*)ptr);
    printf("Value ptr is 'pointing' to (*ptr): %d\n\n", *ptr);

    printf("--- Pass by Value vs. Pass by Pointer ---\n");
    
    // 1. Pass by Value (A copy is made)
    square_by_value(x);
    printf("After square_by_value, x is still: %d\n", x);

    // 2. Pass by Pointer (We give the function the address)
    square_by_pointer(&x);
    printf("After square_by_pointer, x is now: %d\n", x);

    return 0;
}

// This function gets a COPY of the number. 
// It can't change the original 'x' in main.
void square_by_value(int n) {
    n = n * n;
}

// This function gets the ADDRESS of the number.
// The '*' operator here 'dereferences' the pointer to get to the real value.
void square_by_pointer(int *p_n) {
    *p_n = (*p_n) * (*p_n); // We go to the address and change the value there!
}
