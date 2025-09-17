/*
* List.cpp   ***Using a SHSL list ***
* 
* Class Description: List data collection class (ADT) where elements 
*                    - are unsorted, but relative order is kept
*                    - can be duplicated
*                    List position of elements start at 1 (not 0). 
*
* Last Modification: July 2025
* Author: Jerry Meng
*/

#include <iostream>
#include <cstddef> 
#include "List.h"

using std::cout;
using std::endl;

/* Method Implementations */

// Default Constructor
List::List(){
    head = nullptr;
    elementCount = 0;
}

// Destructor - O(n) Time Efficiency
List::~List(){

    // Start off with the first node(head)
    Node * currentNode = head;
    while(currentNode != nullptr){

        // Hold mem add. of the next linked node
        Node * nextNode = currentNode->next; 

        // Free their memory
        delete currentNode;
        currentNode = nextNode;
    }
}

// Description: Returns the current number of elements in the List.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
unsigned int List::getElementCount() const {
    return elementCount;
}

// Description: Insert "newElement" at "position" in the List. 
//              If 1 <= "position" <= getElementCount() + 1 and the insertion
//              is successful, "newElement" is at "position" in the List,
//              the other elements, located after "newElement", "have moved" 1 
//              position up and "true" is returned. Otherwise, "false" is returned.
// Time Efficicency: O(n)
bool List::insert( unsigned int position, int newElement ){

    // Check that position is valid
    if(position < 1 || position > getElementCount() + 1){
        return false;
    }
        
    // Check if we are prepending(position = 1)
    if(position == 1){

        Node * newNode = new Node(newElement, head);
        if(newNode == nullptr){
            return false; // mem. allocation failed
        }

        head = newNode; // update head
        elementCount++;
        return true;
    }   

    // Otherwise, traverse to 'position'
    Node * currentNode = head;
    for(unsigned int i = 1; i < position - 1; i++){
        currentNode = currentNode->next;
    }

    // Insert newNode
    Node * newNode = new Node(newElement, currentNode->next);
    if(newNode == nullptr){
        return false;
    }

    currentNode->next = newNode;    // link the node before 'newNode' up 
    elementCount++;
    return true;
}

// Description: Removes the element at "position" in the List 
//              If 1 <= "position" <= getElementCount() and the removal 
//              is successful, the element at "position" in the List is 
//              removed, and other elements "have moved" 1 position down, 
//              and "true" is returned. Otherwise, "false" is returned.  	
// Time Efficicency: O(n)
bool List::remove( unsigned int position ){

    // Check position
    if(position < 1 || position > getElementCount()){
        return false;
    }

    // Handle Special case for head
    if(position == 1){
        Node * headNode = head;
        head = headNode->next;

        delete headNode;
        headNode = nullptr;
        elementCount--;
        return true;
    }

    // General cases
    Node * currentNode = head;
    for(unsigned int i = 1; i < position - 1; i++){
        currentNode = currentNode->next;
    }
    
    // Remove element 
    Node * removeNode = currentNode->next;
    currentNode->next = removeNode->next;
    delete removeNode;
    elementCount--;
    return true;
}

// Description: Returns the element at "position" in the List
//              in *toBeReturned if 1 <= position <= getElementCount().
//              If successful, returns "true". Otherwise, returns "false".
// Postcondition: List unchanged.
// Time Efficicency: O(n)
bool List::getElement( unsigned int position, int * toBeReturned ) const {

    // Check position
    if(position < 1 || position > getElementCount()){
        return false;
    }
    // Traverse to Node at 'position'
    Node * currentNode = head;
    for(unsigned int i = 1; i < position; i++){
        currentNode = currentNode->next;
    }
    // Return element
    *toBeReturned = currentNode->data;
    return true;
}

// Description: Replaces the element at "position" in the List by "newElement".
//              if 1 <= "position" <= getElementCount(). 
//              If successful, returns "true". Otherwise, returns "false".
// Time Efficicency: O(n)
bool List::setElement( unsigned int position, int newElement ){

    // Check position
    if(position < 1 || position > getElementCount()){
        return false;
    }

    // Traverse to Node at 'position'
    Node * currentNode = head;
    for(unsigned int i = 1; i < position; i++){
        currentNode = currentNode->next;
    }

    // Set element
    currentNode->data = newElement;
    return true;
}

// Description: Prints all elements in the List.
// Format: "This List has <elementCount> elements: { <element 1> ... <element n-1> }"	
// Postcondition: List unchanged.
// Time Efficicency: O(n)
void List::printList() const {
    Node * currentNode = head;

    cout << "This List has " << elementCount << " elements: { ";
    while(currentNode != nullptr){
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << "}" << endl;
    return;
}	