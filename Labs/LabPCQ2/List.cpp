/*
* List.cpp     ***Using a DHSL list as a data structure.***
* 
* Class Description: List data collection class (ADT) where elements 
*                    - are unsorted, but relative order is kept
*                    - can be duplicated
*                    List position of elements start at 1 (not 0).
*
* Modified on: Aug 2025
* Author: Jerry Meng
*/       

#include "List.h"
#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

/* Method Implementations */

// Default Constructor
List::List(){
    head = nullptr;
    tail = nullptr;
    elementCount = 0;
}

// Destructor
List::~List(){

    // Start at first Node if exists
    Node * currentNode = head; 
    while(currentNode != nullptr){

        // Hold mem. address of next linked node
        Node * nextNode = currentNode->next;
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

// Description: Inserts "newElement" at the back of the List 
//              and returns "true" if successful, "false" otherwise.
// Time Efficicency: O(1)  
bool List::append( int newElement ){

    // Create the new node that holds 'newElement'
    Node * newNode = new Node(newElement);
    if(newNode == nullptr){
        return false; // mem allocation failed
    }

    // Special Case: If empty list
    if(head == nullptr){
        head = newNode; 
        tail = newNode; 
    }

    // General case
    else{
        tail->next = newNode;
        tail = newNode;
    }
    
    elementCount++;
    return true;
}

// Description: Inserts "newElement" at the front of the List 
//              and returns "true" if successful, "false" otherwise.
// Time Efficicency: O(1)
bool List::prepend( int newElement ){

    // Create the new node that holds 'newElement'
    Node * newNode = new Node(newElement);
    if(newNode == nullptr){
        return false; // mem allocation failed
    }

    // SPecial Case: If empty list
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }

    // General case
    else{
        newNode->next = head;
        head = newNode; 
    }

    elementCount++;
    return true;
}

// Description: Removes the element from the front of the List 
//              and returns "true" if successful, "false" otherwise. 
// Precondition: List is not empty.
// Time Efficicency: O(1)
bool List::removeAtFront( ){

    // Check precondition
    if(head == nullptr || elementCount == 0){
        return false;
    }

    Node * headNode = head;
    head = headNode->next;
    delete headNode;
    elementCount--;

    // Case: No elements left
    if(head == nullptr){
        tail = nullptr;
    }

    return true;
}

// Description: Returns via the parameter "frontElement" the element 
//              at the front of the List and returns "true" if 
//              successful, "false" otherwise. 
// Precondition: List is not empty.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
bool List::getFrontElement( int * frontElement ) const {

    // Check precondition
    if(head == nullptr || elementCount == 0){
        return false;
    }

    *frontElement = head->data;
    return true;
}

// Description: Prints all elements in the List.
// Format: "This List has <elementCount> elements: { <element  1> ... <element n> }"	
// Postcondition: List unchanged.
// Time Efficicency: O(n)
void List::printList() const {

    cout << "This List has " << elementCount << " elements: { ";

    Node * currentNode = head;
    while(currentNode != nullptr){
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << "}" << endl;
    return;
}