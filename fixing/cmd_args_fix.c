#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Goal: Take integers as command line arguments and sum them.
    // Usage example: ./cmd_args_fix 5 10 15
    // Expected Output: Sum of arguments: 30

    int sum = 0;

    // Bug 1: Starting at index 0 (the program name) will lead to problems!
    // Bug 2: The loop condition (i <= argc) is an off-by-one error.
    // Bug 3: argv[i] is a string (char*), you can't add it directly to an int.
    for (int i = 1; i <= argc - 1; i++) { 
        sum += atoi(argv[i]); 
    }

    printf("Sum of arguments: %d\n", sum);

    return 0;
}
