#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * DEBUGGING CHALLENGE: "The Student Record System"
 * 
 * This program is supposed to:
 * 1. Read student names and their scores.
 * 2. Calculate the average score.
 * 3. Find the student with the highest score.
 * 4. Clean up all memory.
 * 
 * BUGS TO FIND:
 * - At least 1 Memory Leak.
 * - At least 1 Buffer Overflow potential.
 * - An Off-by-one error.
 * - A Null Pointer Dereference risk.
 * - A Logic error in calculation.
 * 
 * Compile with: gcc -o debug_me debug_me.c -g
 * Run and fix it!
 */

typedef struct {
    char *name;
    int score;
} Student;

void add_student(Student **list, int *count, const char *name, int score) {
    *list = realloc(*list, (*count + 1) * sizeof(Student));
    
    // BUG 1: Potential Buffer Overflow or Memory Issue?
    // Let's allocate exactly the length of the name.
    char *new_name = malloc(strlen(name) + 1); 

    if(new_name == NULL) {
        perror("Null Exception, for student name");
    } else {
        strcpy(new_name, name);
        (*list)[*count].name = new_name;
        (*list)[*count].score = score;
        (*count)++;
    }
}

float calculate_average(Student *list, int count) {
    float total = 0;
    // BUG 2: Off-by-one or logic error?
    for (int i = 0; i < count; i++) {
        total += list[i].score;
    }
    return total / (float)count; // BUG 3: Integer division?
}

void find_top_student(Student *list, int count) {
    if (count == 0) return;

    Student *top = &list[0];
    for (int i = 1; i < count; i++) {
        if (list[i].score > top->score) {
            top = &list[i];
        }
    }
    printf("Top Student: %s with %d\n", top->name, top->score);
}

int main() {
    Student *students = NULL;
    int count = 0;

    printf("--- Student Record System ---\n");

    add_student(&students, &count, "Alice", 85);
    add_student(&students, &count, "Bob", 92);
    add_student(&students, &count, "Charlie", 78);
    add_student(&students, &count, "Eve", 95);

    printf("Total students: %d\n", count);
    
    float avg = calculate_average(students, count);
    printf("Average Score: %.2f\n", avg);

    find_top_student(students, count);

    // BUG 4: Memory Leak(s)?
    //
    for(int i = 0; i < count; i++) {
        free(students[i].name);
    }

    free(students);

    return 0;
}
