#include <stdio.h>
#include <string.h>
#include <ctype.h>

void check_palindrome(char *p) {
    int left = 0;
    int right = strlen(p) - 1;

    while (left < right) {
        // Compare characters (converting both to lowercase)
        if (tolower(p[left]) != tolower(p[right])) {
            printf("This is NOT a palindrome :(\n");
            return;
        }
        left++;
        right--;
    }

    printf("This IS a palindrome!!!\n\n");
}

int main() {
    char phrase[100];

    printf("Enter a word: ");
    // Limit input to 99 chars to prevent buffer overflow
    if (scanf("%99s", phrase) == 1) {
        check_palindrome(phrase);
    }

    return 0;
}
