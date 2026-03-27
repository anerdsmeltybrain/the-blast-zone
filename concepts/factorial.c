#include <stdio.h>

int main() {
  int result, factorial, counter = 0;

  printf("Please input a number to factorial: ");
  scanf("%d", &factorial);

  result = counter = 1;

  while( counter < factorial ) {
    result *= counter;
    counter++;
  }

  printf("%d factorial is %d", factorial, result);
  return 0;
}
