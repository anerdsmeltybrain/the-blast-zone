#include <stdio.h>

int power (int power, int num) {
  int result = 1;
  for(int i = 0; i < power; i++) {
    result *= num;
  }
  return result;
}

int main() {

  int pow = 0;
  int natural = 0;
  int sum = 0;
  char buffer[10000];
  printf("Enter a number: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%d", &natural);
  printf("Enter a power: ");
  fgets(buffer, sizeof(buffer), stdin);
  sscanf(buffer, "%d", &pow);

  for(int i = 0; i <= natural; i++) {
    sum += power(pow, i);
  }

  printf("The total of natural squares is: %d", sum);

  return 0;
}
