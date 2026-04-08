#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
   CHALLENGE: 
   1. Fix the compilation errors (missing headers/incorrect types).
   2. Fix the logic in reverse_string() so it actually reverses the string.
   3. Fix the memory management (buffer sizes and leaks).
   4. Bonus: Make the input reading safer.
*/

char* reverse_string(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len * sizeof(char) + 1); 

    for (int i = 0; i <= len - 1; i++) {
        reversed[i] = str[len - 1 - i];
    }

    reversed[len] = '\0';

    return reversed;
}

int main() {
    char input[20];
    printf("Enter a word (max 19 chars): ");
    scanf("%19s", input);

    char* result = reverse_string(input);
    
    printf("Original: %s\n", input);
    printf("Reversed: %s\n", result);

    free(result);

    return 0;
}
