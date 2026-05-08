/* numbers.c */
#include <stdio.h>

int main() {
  int numOne, numTwo;

  printf("Please input a number\n");
  scanf("%d", &numOne);
  printf("Please input another number\n");
  scanf("%d", &numTwo);

  printf("%d + %d is: %d\n", numOne, numTwo, numOne + numTwo);

  return 0;
}
