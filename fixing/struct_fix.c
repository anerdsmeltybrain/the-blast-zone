#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

// Goal: Update the person's age.
// This function doesn't work!
void update_age(struct Person * p, int new_age) {
    p->age = new_age;
}

int main() {
    struct Person bob;
    strcpy(bob.name, "Bob");
    bob.age = 25;

    printf("Before update: %s is %d years old.\n", bob.name, bob.age);

    // Try to update Bob's age to 30
    update_age(&bob, 30);

    printf("After update:  %s is %d years old.\n", bob.name, bob.age);
    printf("Expected:     Bob is 30 years old.\n");

    return 0;
}
