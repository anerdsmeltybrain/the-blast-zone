#include <stdio.h>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    
    // An array's name is actually just a pointer to its first element!
    int *ptr = numbers; 

    printf("--- Array vs Pointer Access ---\n");
    printf("First element (array style): %d\n", numbers[0]);
    printf("First element (pointer style): %d\n\n", *ptr);

    printf("--- Pointer Arithmetic (Moving through memory) ---\n");
    // When we add 1 to a pointer, it moves to the NEXT integer in memory.
    printf("Second element: %d\n", *(ptr + 1));
    printf("Third element:  %d\n", *(ptr + 2));

    printf("\n--- The Secret Identity ---\n");
    for (int i = 0; i < 5; i++) {
        // These two lines do EXACTLY the same thing:
        printf("Index %d: Array syntax [%d] == Pointer syntax [%d]\n", 
               i, numbers[i], *(numbers + i));
    }

    return 0;
}
