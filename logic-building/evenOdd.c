#include <stdio.h>

int main() {
  int num = 0;
  printf("Please enter a number: ");
  scanf("%d", &num);

  if(num % 2 == 0) {
    printf("True\n");
    printf("%d % %d = 0, so %d is even\n", num, 2, num);
  } else if (num % 2 == 1) {
    printf("False\n");
    printf("%d % %d = 1, so %d is false\n", num, 2, num);
  }
}
