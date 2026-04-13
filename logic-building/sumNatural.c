#include <stdio.h>
#include <stdlib.h>

int main([[maybe_unused]]int argc, char ** argv) {

  unsigned int natural, result = 0;
  if(argc == 2) {
    natural = atoi(argv[1]);
    goto end;
  } else {
    printf("correct format: <program name> <arg1>\n");
  }

  printf("Please enter a number\n then we will calculate the sum of all natural numbers:");
  scanf("%d", &natural);

end:
  for(int i = 0; i <= natural; i++) {
    result += i;
  }

  printf("The sum of natural numbers of %d is %d\n", natural, result);
  return 0;
}
