/*
 * List.cpp      ***Using a DHSL list as a data structure.***
 * 
 * Class Description: List data collection class (ADT) where elements 
 *                    - are unsorted, but relative order is kept
 *                    - can be duplicated
 *                    List position of elements start at 1 (not 0).
 *
 * Modified on: July 2025
 * Author: AL
 */                 

#include <cstddef>   // Needed for nullptr
#include <iostream>
#include <cmath>
#include <climits>
#include "Node.h"
#include "List.h"

using std::cout;
using std::endl;
	
// Default constructor
List::List() { }

// Destructor
List::~List() {
  while ( getElementCount() > 0 )
    removeAtFront(); 
} 

// Description: Returns the current number of elements in the List.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
// Not to be modified!
unsigned int List::getElementCount() const {
  return elementCount;
}

// Description: Inserts "newElement" at the back of the List 
//              and returns "true" if successful, "false" otherwise.
// Time Efficicency: O(1)
// Not to be modified!
bool List::append( int newElement ) {

  bool result = true;
  
  Node * newNode = new(std::nothrow) Node( newElement );   
  if ( newNode ) {  // Same as "if ( newNode != nullptr )"    

    if ( head == nullptr ) // Empty List
      head = newNode;
  
    if ( tail != nullptr ) // Non-empty list
      tail->next = newNode;

    tail = newNode;
      
    elementCount++; // One more element in the list
  }
  else 
    result = false;
  
  return result;
}
  
// Description: Removes the element from the front of the List 
//              and returns "true" if successful, "false" otherwise. 
// Precondition: List is not empty.
// Time Efficicency: O(1)
// Not to be modified!
bool List::removeAtFront( ) {

  bool result = true;
  
  if ( head != nullptr ) {
    Node * tobeRemoved = head;
    head = head->next;
    
    tobeRemoved->next = nullptr;
    delete tobeRemoved;
    tobeRemoved = nullptr;
      
    if ( head == nullptr ) tail = nullptr;
    
    elementCount--; 
  }
  else 
    result = false;
  
  return result;
} 

// D103-D104
// Description: This method finds the element with the minimum value in
//              the List and returns its position number via the parameter.
//              If there are many elements with the minimum value, it
//              returns the position of the last one. 
//              Careful: The position numbers range from 1 to "elementCount".
//             	This method also prints this minimum value found in the List, 
//              using the following format:
//              "The minimum value found in this list is _____." 
//              replacing the blank "_____" with this minimum value.
//              This method returns "true" if successful, otherwise, "false".
// Precondition: List is not empty.
// Postcondition: List unchanged.
// Time Efficicency: _____O(n)__________  *** Write your Time Efficicency here! ***
bool List::findMin( unsigned int * minPosition ) const {
  
  int minimum;

  // Check precondition
  if(elementCount == 0 || head == nullptr){
    return false;
  }

  // Start at our first node(head)
  Node * currentNode = head;

  // Hold our first value
  minimum = currentNode->data;

  for(unsigned int i = 1; i < elementCount; i++){

    // Traverse each node
    currentNode = currentNode->next;

    // Check for min
    if(currentNode->data <= minimum){
      minimum = currentNode->data;
      *minPosition = i + 1;
    }
  }

  // Print results
  cout << "The minimum value found in this list is " << minimum << "." << endl;
  return true; // Feel free to modify this return statement.
}

// Description: Prints all elements in the List.
// Format: "This List has <elementCount> elements: { <element 1> ... <element n> }"
// Postcondition: List unchanged.
// Time Efficicency: O(n)
// Not to be modified!
void List::printList() const {

  cout << "This List has " << elementCount << " elements: {";
  if ( head != nullptr ) {
    Node * current = head;
    for ( unsigned int i = 1; i <= elementCount; i++ ) {
      cout << " " << current->data;
      current = current->next;
    }
  }
  cout << " }" << endl;
  return;
}
