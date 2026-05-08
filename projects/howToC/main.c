/* how to program in C */

#include <stdio.h>
#include <stdlib.h>


//function declaration
int add(int, int);

int main() {

   int number = 9;

   int x = 5;
   int y = 4;

   printf("Hello, World!!!\n");
   printf("%d is a number\n", number);
   printf("%d + %d is %d\n", x, y, x + y);

   int j = 0;
   int k = 0;

   printf("\nChoose two numbers: \n");
   printf("\nnumber one: ");
   scanf("%d", &j);
   printf("\nnumber two: ");
   scanf("%d", &k);

   int l = j + k;

   printf("l is equal to: %d\n", l);
  

   int numbers[5] = { 1, 2, 3, 4, 5 };

   printf("the first element of the array is %d\n", numbers[0]);

   for(int i = 0; i < 5; i++) {
     printf("the number %d is the element at index %d\n", numbers[i], i);
   }

   int * integers = malloc(5 * sizeof(int));

   *(integers) = 5;
   *(integers + 1 ) = 6;
   *(integers + 2 ) = 7;
   *(integers + 3 ) = 8;
   *(integers + 4 ) = 9;

   printf("the address of integers %p and the value is %d\n", integers, *integers);
   printf("the address of integers %p and the value is %d\n", (integers + 1), *(integers + 1));
   printf("the address of integers %p and the value is %d\n", (integers + 2), *(integers + 2));
   printf("the address of integers %p and the value is %d\n", (integers + 3), *(integers + 3));
   printf("the address of integers %p and the value is %d\n", (integers + 4), *(integers + 4));

   for(int i = 0; i < 5; i++) {
     printf("the address of integers %p and the value is %d\n", (integers + i), *(integers + i));
   }

  int z = add(5, 10); 
    
  printf("the value of z: %d\n", z);

  return 0;
}

//function definition    
int add(int x, int y) {
  return x + y;
}
