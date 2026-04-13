#include <stdio.h>

int main() {
  double fahr, celsius;
  double lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5/9 * (fahr-32) ;
    printf("%lf\t%lf\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}
