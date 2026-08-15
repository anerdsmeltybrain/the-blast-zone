#include <stdio.h>

int sub(int a, int b) {
  return a - b;
}

int main() {

  int x = 15;
  int y = 10;

  int z = sub(x, y);

  printf("%d - %d = %d", x, y, z);

  return 0;
}
