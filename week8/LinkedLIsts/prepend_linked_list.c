#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node_t;

int main() {
    // Create initial node (head)
    Node_t* head = malloc(sizeof(Node_t));
    head->val = 2;
    head->next = NULL;

    // Prepend new node
    Node_t* newNode = malloc(sizeof(Node_t));
    newNode->val = 1;
    newNode->next = head;  // Step 1: point to current head
    head = newNode;        // Step 2: update head

    // Print list
    Node_t* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");

    // Free memory
    free(head->next);  // free node with val 2
    free(head);        // free node with val 1

    return 0;
}
