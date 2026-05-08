#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    const char *filename = "data.txt";
    int numbers[] = {10, 20, 30, 40, 50};
    int n = 5;

    // Goal 1: Write numbers to the file
    fp = fopen(filename, "w");
    // Bug: No check if fp is NULL!
    if (fp == NULL) {
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", numbers[i]);
    }
    // Bug: Forgetting to close the file after writing!

    fclose(fp);

    // Goal 2: Read numbers from the file and sum them
    fp = fopen(filename, "r");
    // Bug: No check if fp is NULL!

    if (fp == NULL) {
        return 1;
    }

    int sum = 0;
    int num;
    
    // Bug: Using feof() incorrectly often leads to processing the last line twice!
    while (!feof(fp)) {
        while (fscanf(fp, "%d", &num) == 1)
            sum += num;
    }

    printf("Sum of numbers in file: %d\n", sum);
    printf("Expected Sum: 150\n");

    // Bug: Forgetting to close the file after reading!

    fclose(fp);

    return 0;
}
