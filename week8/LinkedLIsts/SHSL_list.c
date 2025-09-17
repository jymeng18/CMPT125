#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int val;
    struct Node* next;
} Node_t;

int main() {
    // Create 3 nodes
    Node_t* head = malloc(sizeof(Node_t)); // this is a pointer to a struct, 
    Node_t* second = malloc(sizeof(Node_t));
    Node_t* third = malloc(sizeof(Node_t));

    // Assign values and link them
    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = NULL;

    // Print the list (traversing the linked list)
    Node_t* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");

    // Free memory
    free(head);
    free(second);
    free(third);

    return 0;
}
