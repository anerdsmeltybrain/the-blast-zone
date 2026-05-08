#include <stdio.h>

int main() {
  int leapYear;

  printf("Enter a year to check: ");
  scanf("%d", &leapYear);

  if ((leapYear % 4 == 0 && leapYear % 100 != 0) || (leapYear % 400 == 0)) {
    printf("%d: This is a leap year.\n", leapYear);
  } else {
    printf("%d: This is not a leap year.\n", leapYear);
  }

  return 0;
}
