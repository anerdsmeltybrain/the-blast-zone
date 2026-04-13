#include <stdio.h>
#include <stdlib.h>

void multiTable(int num, int length) {

  printf("Multiplication Table for %d\n\n", num);
  for(int i = 0; i < length; i++) {
    printf("%d x %d = %d\n", num, i, i * num);
  }
}

int main(int argc, char ** argv) {

  unsigned int multiple, length = 0;
  if(argc == 3) {
    multiple = atoi(argv[1]);
    length = atoi(argv[2]);
    goto table;
  } else {
    printf("The correct format is\n");
    printf("<Progam Name> <Multiple> <Length>");
  }

multi:
  printf("Please enter a multiplication # > 0");
  scanf("%d", &multiple);

  if(multiple < 0)
    goto multi;

length:
  printf("Please enter a length # > 0");
  scanf("%d", &length);

  if(length < 0)
    goto length;

table:
  multiTable(multiple, length);

  return 0;
}
