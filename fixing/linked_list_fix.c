#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Goal: Create a new node with the given data
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Goal: Add a new node to the end of the list
void append(struct Node* head, int data) {
    struct Node* new_node = create_node(data);
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Goal: Print all elements in the list
void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Try to add 10, 20, 30 to the list
    // This will likely CRASH because head is NULL!
    append(head, 10);
    append(head, 20);
    append(head, 30);

    printf("List: ");
    print_list(head);

    // Missing: free_list function to clean up memory!

    return 0;
}
