/* calculator program */

#include <stdio.h>

//number chooser
void choiceChooser(int *);

//math operations
int add(int, int);
int sub(int, int);
int mult(int, int);
int divide(int, int);

int main() {

  int num1, num2, choice;

  int (*operation)(int, int) = NULL;

  choiceChooser(&num1);
  choiceChooser(&num2);
  choiceChooser(&choice);

  switch(choice) {
    case 1:
      operation = add;
      printf("you chose addition!\n");
      printf("%d + %d = %d\n", num1, num2, operation(num1, num2));
      break;
    case 2:
      operation = sub;
      printf("you chose addition!\n");
      printf("%d - %d = %d\n", num1, num2, operation(num1, num2));
      break;
    case 3:
      operation = mult;
      printf("you chose addition!\n");
      printf("%d * %d = %d\n", num1, num2, operation(num1, num2));
      break;
    case 4:
      operation = divide;
      printf("you chose addition!\n");
      printf("%d / %d = %d\n", num1, num2, operation(num1, num2));
      break;
  }

  

  return 0;
}

void choiceChooser(int * number) {
  static int choiceCount = 1;

  if(choiceCount <= 2) {
    printf("Please enter a number [choice %d]: \n", choiceCount);
    scanf("%d", number);
  } else {
    do {
      printf("Please enter a choice: \n");
      printf("[1 : add | 2 : subtract | 3 : multiply | 4 : divide]: \n");
      scanf("%d", number);
    } while (*number < 1 || *number > 4);
  }

  choiceCount++;
}

int add(int num1, int num2) {
  int result = num1 + num2;
  return result;
}

int sub(int num1, int num2) {
  int result = num1 - num2;
  return result;
}

int mult(int num1, int num2) {
  int result = num1 * num2;
  return result;
}

int divide(int num1, int num2) {
  int result = num1 / num2;
  return result;
}

