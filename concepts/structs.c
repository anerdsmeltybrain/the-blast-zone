#include <stdio.h>
#include <string.h>

// 1. Defining the 'Blueprint' for a Student
struct Student {
    char name[50];
    int age;
    float grade;
};

// Function that takes a struct as an argument
void print_student(struct Student s) {
    printf("--- Student Details ---\n");
    printf("Name:  %s\n", s.name);
    printf("Age:   %d\n", s.age);
    printf("Grade: %.2f\n\n", s.grade);
}

int main() {
    // 2. Creating an 'Instance' (a real student)
    struct Student s1;

    // 3. Filling in the fields using the '.' (dot) operator
    strcpy(s1.name, "Alice"); // Using strcpy to copy text into the array
    s1.age = 20;
    s1.grade = 88.5;

    // 4. Another way to initialize a struct (shorthand)
    struct Student s2 = {"Bob", 21, 92.0};

    // Printing the students
    print_student(s1);
    print_student(s2);

    return 0;
}
