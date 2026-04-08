#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
   CHALLENGE: 
   1. Fix the "Dangling Pointer" bug in create_user().
   2. Fix the crashing bug in print_user().
   3. Fix the memory management in main().
   4. Correct the syntax for accessing structure members via pointers.
*/

typedef struct {
    char name[50];
    int id;
} User;

User* create_user(char* name, int id) {
    User * u = malloc(sizeof(User)); // Local variable
    strcpy(u->name, name);
    u->id = id;
    return u; // returning address of local variable
}

void print_user(User* u) {
    // Incorrect syntax for pointer access
    printf("User ID: %d, Name: %s\n", u->id, u->name);
}

int main() {
    User* my_user = create_user("Alice", 101);

    print_user(my_user);

    // Something is missing here to clean up...

    free(my_user);
    
    return 0;
}
