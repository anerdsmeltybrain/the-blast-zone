#include <stdio.h>
#include <string.h>

int main() {
    char original[] = "Hello";
    char reversed[6]; // "Hello" has 5 characters + 1 for null terminator
    int len = strlen(original);

    // Goal: Reverse "Hello" into reversed[]
    // Expected: "olleH"
    for (int i = 0; i <= len - 1; i++) {
        reversed[i] = original[len - i - 1];
    }

    reversed[len] = '\0';

    printf("Original: %s\n", original);
    printf("Reversed: %s\n", reversed);
    printf("Expected: olleH\n");

    return 0;
}
