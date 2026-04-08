#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * DEBUGGING CHALLENGE: "The Broken Inventory"
 * 
 * This program manages an inventory using a linked list.
 * It's supposed to:
 * 1. Add items to the front of the list.
 * 2. Delete an item by its name.
 * 3. Print the entire inventory.
 * 4. Free all memory at the end.
 * 
 * BUGS TO FIND:
 * - A "Lost Node" memory leak when deleting.
 * - A crash when deleting the last item or from an empty list.
 * - A "Use-after-free" bug.
 * - A logic error where the list head isn't updated correctly.
 * 
 * Compile with: gcc -o linked_list linked_list.c -g
 */

typedef struct Item {
    char name[32];
    int quantity;
    struct Item *next;
} Item;

// Adds a new item to the beginning of the list
void add_item(Item **head, const char *name, int qty) {
    Item *new_item = malloc(sizeof(Item));
    strncpy(new_item->name, name, 31);
    new_item->quantity = qty;
    
    // BUG: Is the 'next' pointer initialized?
    new_item->next = *head;
    *head = new_item;
}

// Removes an item by name
void remove_item(Item **head, const char *name) {
    Item *current = *head;
    Item *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            // Found it!
            if (prev == NULL) {
                // Removing the head
                *head = current->next;
            } else {
                // Removing from middle or end
                prev->next = current->next;
            }
            
            // BUG: Potential issues during/after free?
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void print_inventory(Item *head) {
    printf("Current Inventory:\n");
    while (head != NULL) {
        printf("- %s: %d\n", head->name, head->quantity);
        head = head->next;
    }
}

void clear_inventory(Item *head) {
    // BUG: This is a very common linked list mistake!
    while (head != NULL) {
        free(head);
        head = head->next; 
    }
}

int main() {
    Item *inventory = NULL;

    add_item(&inventory, "Potions", 5);
    add_item(&inventory, "Arrows", 20);
    add_item(&inventory, "Swords", 2);

    print_inventory(inventory);

    printf("\nRemoving Arrows...\n");
    remove_item(&inventory, "Arrows");
    print_inventory(inventory);

    printf("\nRemoving Potions...\n");
    remove_item(&inventory, "Potions");
    print_inventory(inventory);

    // Final cleanup
    clear_inventory(inventory);

    return 0;
}
