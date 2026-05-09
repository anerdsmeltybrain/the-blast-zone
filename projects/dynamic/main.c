/* dynamic memory allocation */

#include <stdio.h>
#include <stdlib.h>

int main() {

  int input = 0;
  int multiple = 0;

  printf("Please how many numbers for the \nmultiplicaiton table: ");
  scanf("%d", &input);

  printf("\nWhat number to multiply by: ");
  scanf("%d", &multiple);

  int * numbers = malloc(input * sizeof(int));

  printf("===\tMultiplication Table for %d\t===\n", input);
  for(int i = 0; i < input; i++) {
    *(numbers + i) = multiple * i;
  }

  for(int i = 0; i < input; i++) {
    printf("%d x %d = %d\n", multiple, i, *(numbers + i));
  }

  int * numPointer = numbers + 2;

  // *numPointer = 5;

  printf("numPointer address: %p | numPointer value: %d\n", &numPointer, *numPointer);

  
  free(numbers);

  if (!numbers) {
    printf("NUMBERS IS NULL\n");
  }
 
  return 0;
}
