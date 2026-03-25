#include <stdio.h>

int main() {

  int number;

  printf("Please enter a number: ");
  scanf("%d", &number);

  if (number % 2 == 0) {
    printf("%d is even :D\n", number);
  } else {
    printf("%d is odd :D\n", number);
  }

  return 0;
}
