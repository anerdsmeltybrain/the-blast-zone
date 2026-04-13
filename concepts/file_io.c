#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[] = "example.txt";
    FILE *fptr;

    // 1. Writing to a file ("w" mode)
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    fprintf(fptr, "Hello, this is a file I/O demo.\n");
    fprintf(fptr, "The number is: %d\n", 42);
    
    fclose(fptr);
    printf("Successfully wrote to %s\n", filename);

    // 2. Reading from a file ("r" mode)
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    char buffer[100];
    printf("\nReading content from %s:\n", filename);
    while (fgets(buffer, 100, fptr) != NULL) {
        printf("%s", buffer);
    }

    fclose(fptr);

    // 3. Appending to a file ("a" mode)
    fptr = fopen(filename, "a");
    if (fptr == NULL) {
        perror("Error opening file for appending");
        return 1;
    }

    fputs("This line was appended later.\n", fptr);
    fclose(fptr);
    printf("\nSuccessfully appended to %s\n", filename);

    return 0;
}
