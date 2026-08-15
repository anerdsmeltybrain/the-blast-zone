#include <stdio.h>

int main() {

  for(int i = 99; i > 0; i--) {
    if (i > 1) {
      printf("%d bottles of rum\n", i);
    } else if ( i == 1 ) {
      printf("just %d bottle of rum left\n", i);
    }
  }

  return 0;
}
