#include <stdio.h>

int factorial(int factor) {

  int result = 1;

  for(int i = 1; i <= factor; i++) {
    result *= i;
  }

  return result;
}

int main() {

  int factor = 0;

  printf("Please enter your factorial\n");
  scanf("%d", &factor);

  int result = factorial(factor);

  printf("%d, this is the factorial of %d", factor, result);

  return 0;
}
