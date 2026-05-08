#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum taskSwitch {
  ADDTASK = 1,
  DELETETASK,
  PRINTTASK
};

struct task {
  int index;
  bool isComplete;
  char taskDescription[100];
  char dateCreated[30];
};

struct taskList {
  int capacity;
  struct task * taskList;
};

void addTask(FILE *, const char *, struct taskList *);
void deleteTask(FILE *, const char *, struct taskList *);
void printTaskList(FILE *, const char *, struct taskList *);

int main(int argc, char ** argv) {

  FILE *fp;
  const char * filename = "tasks.txt";
  struct taskList * taskL = malloc(sizeof (struct taskList));
  taskL->capacity = 0;
  taskL->taskList = malloc(sizeof (struct task));
  enum taskSwitch choice;
  char buffer[100];


  printf("\033[2J\033[H");
  printf("\nWelcome to your tasks list!~\n");

  while(true) {

  // printf("\033[2J\033[H");
  // printf("\nWelcome to your tasks list!~\n");

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &choice);
    switch(choice) {
      case ADDTASK:
        addTask(fp, filename, taskL);
        printf("added task\n");
        break;
      case DELETETASK:
        deleteTask(fp, filename, taskL);
        break;
      case PRINTTASK:
        printTaskList(fp, filename, taskL);
        printf("printed task list\n");
        break;
      default:
        printf("Please enter a valid choice!\n");
        break;
    }
  }

  free(taskL->taskList);
  free(taskL);
  return 0;
}

void addTask(FILE * fp, const char * fileName, struct taskList * taskList) {

  taskList->taskList = realloc(taskList->taskList, (taskList->capacity + 1) * sizeof(struct task));

  time_t t = time(NULL);
  struct tm *tm_info = localtime(&t);

  printf("Please Enter Task Description\n");
  fgets(taskList->taskList[taskList->capacity].taskDescription, 100, stdin);
  taskList->taskList[taskList->capacity].taskDescription[strcspn(taskList->taskList[taskList->capacity].taskDescription, "\n")] = 0;

  taskList->taskList[taskList->capacity].index = taskList->capacity + 1;
  taskList->taskList[taskList->capacity].isComplete = false;
  strftime(taskList->taskList[taskList->capacity].dateCreated, 30, "%Y-%m-%d %H:%M:%S", tm_info);
  
  taskList->capacity++;
}
void deleteTask(FILE * fp, const char * fileName, struct taskList * taskList) {
  if (taskList->capacity == 0) {
    printf("No tasks to delete.\n");
    return;
  }

  int indexToDelete;
  printf("Enter the index of the task to delete: ");
  char buffer[100];
  if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
  if (sscanf(buffer, "%d", &indexToDelete) != 1) {
    printf("Invalid input. Please enter a number.\n");
    return;
  }

  int foundIndex = -1;
  for (int i = 0; i < taskList->capacity; i++) {
    if (taskList->taskList[i].index == indexToDelete) {
      foundIndex = i;
      break;
    }
  }

  if (foundIndex == -1) {
    printf("Task with index %d not found.\n", indexToDelete);
    return;
  }

  // Shift elements to the left
  for (int i = foundIndex; i < taskList->capacity - 1; i++) {
    taskList->taskList[i] = taskList->taskList[i + 1];
    // Re-index to keep them sequential
    taskList->taskList[i].index = i + 1;
  }

  taskList->capacity--;
  
  // Reallocate memory to new size
  if (taskList->capacity > 0) {
    struct task *temp = realloc(taskList->taskList, taskList->capacity * sizeof(struct task));
    if (temp != NULL) {
      taskList->taskList = temp;
    }
  } else {
    // If no tasks left, keep a minimal allocation to avoid issues with addTask's realloc
    struct task *temp = realloc(taskList->taskList, sizeof(struct task));
    if (temp != NULL) {
      taskList->taskList = temp;
    }
  }

  printf("Task %d deleted successfully.\n", indexToDelete);
}
void printTaskList(FILE * fp, const char * fileName, struct taskList * taskList) {
  for(int i = 0; i < taskList->capacity; i++) {
    printf("index %d:[%d] %s | %s\n",
           taskList->taskList[i].index,
           taskList->taskList[i].isComplete,
           taskList->taskList[i].taskDescription,
           taskList->taskList[i].dateCreated);
  }
}
