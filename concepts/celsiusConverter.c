#include <stdio.h>

int main () {

  double celsius, fahr = 0;

  printf("Welcome to the celsius to fahrenheit converter~\n");
  printf("Please enter a number(celsius): \n");
  scanf("%lf", &celsius);

  fahr = (celsius * 9.0/5.0) + 32;

  printf("%.2lf celsius is %.2lf fahrenheit\n", celsius, fahr);

  return 0;
}
