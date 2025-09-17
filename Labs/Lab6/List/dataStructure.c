/* 
 * dataStructure.c
 *
 * Provides a data structure made of a doubly-headed singly-linked list 
 * (DHSL) of unsorted elements, in which duplicated elements are allowed.
 * 
 * A DHSL list is comprised of a single variable of data type list_t
 * and zero or more elements, where each element is stored in a node variable of
 * data type element_t. The struct list_t contains a pointer (called "head") to 
 * the first element (node in the list) in the list and a pointer (called "tail") to 
 * the last element (node) of the list. It also keeps track of the number of elements  
 * (nodes) in the list. If the list is empty, both "head" and "tail" pointers are 
 * set to NULL and "elementCount" is set to 0.
 * The first element (node in the list) contains a pointer to the "next" element,
 * and so on. The last element in the list (last node) has its "next" pointer set 
 * to NULL.
 * 
 * The interface of this data structure includes several utility 
 * functions that operate on this data structure.
 *
 * Precondition: Functions that operate on such data structure
 *               require a valid pointer to it as their first argument.
 *
 * Do not change this dataStructure.h file.
 *
 * Your name: Jerry Meng 
 * Modified Date: July 2025
*/

#include <stdio.h>
#include <stdlib.h>

#include "dataStructure.h"


/* 
 * Description: Creates a new empty data structure of list_t type and 
 *              if successful, returns a pointer to it. 
 *              If unsuccessful, returns NULL.
 * Time Efficiency: O(1)
 */
list_t * list_create( void ) {

  list_t * aList = malloc( sizeof(list_t) );

  // Ensure memory was allocated
  if(aList == NULL){
    return NULL;
  }

  // No nodes have been added
  aList->head = NULL;
  aList->tail = NULL;
  aList->elementCount = 0;

  return aList;
}

/*
 * Description: Frees all memory used by the data structure pointed to by "list". 
 *              Returns LIST_OK on success, otherwise returns LIST_ERROR.
 * Time Efficiency: O(n)
 */ 
listResult_t list_destroy( list_t * list ) {
  
  if(list == NULL) return LIST_ERROR;

  // Start at head node
  element_t * current = list->head;
  
  while(current != NULL){

    // Temporarily hold the mem. address of the next linked node
    element_t * nextNode = current->next;

    free(current);

    // Move to next node
    current = nextNode;
  }
  free(list);
  return LIST_OK; // You are free to modify this return statement or not.
}

/* 
 * Description: Returns a pointer to a new element i.e., a node  
 *              containing "newElement" and its "next" pointer set to NULL, 
 *              or NULL if memory allocation fails.
 * Time Efficiency: O(1)
 */
element_t * element_create( int newElement ) {

  element_t * anElement = malloc( sizeof(element_t) );
  if(anElement == NULL){
    return NULL;
  }

  // Set val as newElement
  anElement->val = newElement;
  anElement->next = NULL;
  return anElement;
}

/* Description: Appends a new element, i.e., a node containing "newElement", 
 *              to this data structure pointed to by "list" and returns LIST_OK. 
 *              If "newElement" cannot be appended, leaves the 
 *              data structure unmodified and returns LIST_ERROR.
 *              Returns LIST_NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
listResult_t list_append( list_t * list, int newElement ) {
	
  if(list == NULL) return LIST_NULL_PARAM;

  // Create this new node containing newElement
  element_t * newNode = element_create(newElement);

  // Check that memory allocated correctly
  if(newNode == NULL) return LIST_ERROR;

  // Check that its not empty list
  if(list->head == NULL || list->elementCount == 0){
    list->head = newNode;
    list->tail = newNode;
  }

  // Executing this means list was not empty
  else{
    // Modify the node before to point(link) at our newly appended node
    list->tail->next = newNode; 

    // Tail was pointing at node before, change it to point at the newly appended(last) node
    list->tail = newNode;
  }

  // After appending, increment elementCount
  list->elementCount++;
  return LIST_OK; // You are free to modify this return statement or not.
}

/* Description: Prepends a new element, i.e., a node containing "newElement", 
 *              to this data structure pointed to by "list" and returns LIST_OK. 
 *              If "newElement" cannot be prepended, leaves the 
 *              data structure unmodified and returns LIST_ERROR.
 *              Returns LIST_NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
listResult_t list_prepend( list_t * list, int newElement ) {
  
  listResult_t result = LIST_OK;

  // Returns LIST_NULL_PARAM if "list" is NULL.
  if ( list == NULL ) result = LIST_NULL_PARAM; 
  else {
	// Creates a new element (node) containing "newElement" 
    element_t * anElement = element_create( newElement );    
    if ( anElement == NULL ) result = LIST_ERROR;
    else {
      if ( list->tail == NULL ) // Empty list
        list->tail = anElement;
  
      if ( list->head ) // Non-empty list
        anElement->next = list->head;

      list->head = anElement;

      // Record the fact that there is one more element in the list
      list->elementCount++; 
    }
  }  
  return result;
}

/* Description: Removes the front (first) element (node) from the data 
 *              structure pointed to by "list" and returns LIST_OK. 
 *              If no elements (no nodes) can be removed, leaves the 
 *              data structure unmodified and returns LIST_ERROR.
 *              Returns LIST_NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
listResult_t list_removeFront( list_t * list ) {
	
  if(list == NULL) return LIST_NULL_PARAM;
  if(list->elementCount == 0) return LIST_ERROR;

  // Remove(free) first element
  element_t * newHead = list->head->next; // this will be nullptr if only one node to start
  free(list->head);
  list->head = newHead;

  // Special Case: There was only one node to begin with
  if(list->head == NULL){
    list->tail = NULL; 
  }

  // After removing a node, decrement elementCount
  list->elementCount--;

  return LIST_OK; // You are free to modify this return statement or not.
}
							
/* Description: Returns a pointer to the element (node) at "position" 
 *              in the data structure pointed to by "list". 
 *              To determine the proper "position" in the list,
 *              know that the first element (node) in the list is 
 *              at "position" 1, the second element (node) is at 
 *              "position" 2, etc. Returns NULL if "position" is 
 *              out of range. Returns NULL if "list" is NULL.
 *              This function does not modify the data structure.
 * Time efficiency: O(n)
 */
element_t * list_get( list_t * list, unsigned int position ){

  if(list == NULL || list->head == NULL){ 
    return NULL;
  }

  // Check that position is within range
  if(position > list->elementCount || position < 1){
    return NULL;
  }

  // Traverse to position n
  element_t * currentNode = list->head;
  for(unsigned int i = 1; i < position; i++){
    currentNode = currentNode->next;
  }
  
  // Return the ptr to the node at position n
  return currentNode; 
}

/* Description: Returns a pointer to the element (i.e., to the node) that 
 *              contains the first occurrence of "targetElement" in the data 
 *              structure pointed to by "list". Returns NULL if "targetElement"
 *              is not found. Returns NULL if "list" is NULL.
 *              This function does not modify the data structure.
 * Time efficiency: O(n)
 */ 
element_t * list_find( list_t * list, int targetElement ) {

  if(list == NULL || list->head == NULL){
    return NULL;
  }
  
  // Set our currentNode to the very first element(Node)
  element_t * currentNode = list->head;

  while(currentNode != NULL){
    if (currentNode->val == targetElement) {
        return currentNode;
    }
    // Traverse to next node
    currentNode = currentNode->next;
}
  
  // If execution point reaches here, targetElement was not found.
  return NULL; 
}

/* Description: Prints the content of the data structure pointed to by "list",
 *              printing the list in human-readable form from the first element
 *              (in the first node) to the last element (in the last node), 
 *              between curly braces, then returns LIST_OK. 
 *              Returns LIST_NULL_PARAM if "list" is NULL.
 *              This function does not modify the data structure.
 * Time Efficiency: O(n)
 */
listResult_t list_print( list_t * list ) {

  listResult_t result = LIST_OK;

  // Returns LIST_NULL_PARAM if "list" is NULL.
  if ( list == NULL ) result = LIST_NULL_PARAM;
  else {  
    printf( "This data structure has %d element%c:\n", list->elementCount,
             list->elementCount > 0 ? 's': ' ' );
    printf( "{" );
  
    // Prints each element
    for ( element_t * eachElement = list->head; eachElement; eachElement = eachElement->next )
      printf( " %d", eachElement->val );

    printf( " }\n" );
  }
  
  return result;
}
