#include <stdio.h>
#include "dataStructure.h"

int main() {
    printf("\n\n\n");
    printf("Creating list...\n");
    list_t *list = list_create();
    if (list == NULL) {
        printf("Failed to create list.\n");
        return 1;
    }

    // Test Case 1: Appending
    printf("Appending elements...\n");
    list_append(list, 10);
    list_append(list, 20);
    list_append(list, 40);
    list_append(list, 22);

    printf("Printing list...\n");
    list_print(list);

    // Test Case 2: Remove Front Element(Head)
    // printf("Removing front element...\n");
    // list_removeFront(list);
    // printf("Printing list after removing front element...\n");
    // list_print(list);

    // Test Case 3: list_get function
    printf("Getting element at position 2...\n");
    element_t *second = list_get(list, 2); 
    if (second != NULL)
        printf("Found: %d\n", second->val); // Should be 20
    else
        printf("Not found.\n");

    // Test Case 4: list_find fn
    printf("Finding value first occurence of 20\n");
    element_t *found = list_find(list, 24);
    if (found != NULL)
        printf("Found: %d\n", found->val);
    else
        printf("Not found.\n");

    // Test Case: Destroy Data Structure
    printf("Destroying list...\n");
    if(list_destroy(list) == LIST_OK){
        printf("Datastructure was successfuly destroyed\n");
    }

    return 0;
}
