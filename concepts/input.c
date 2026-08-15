#include <stdio.h>
#include <string.h>

int main() {

  char name[64];

  printf("\nSo what's your name?");
  fgets(name, sizeof(name), stdin);
  name[strlen(name)-1] = '\0';

  printf("Hey, %s, how are you doing!?", name);
  return 0;
}
