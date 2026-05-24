/* fizz buzz */
#include <stdio.h>

int main(void) {

  for(int i = 0; i < 101; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
      printf("%d - FizzBuzz\n", i);
    } else if ( i % 5 == 0 ) {
      printf("%d - Fizz\n", i);
    } else if ( i % 3 == 0 ) {
      printf("%d - Buzz\n", i);
    }
  }

  return 0;
}
