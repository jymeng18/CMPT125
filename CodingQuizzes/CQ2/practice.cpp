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
    Node * currentNode = head;
    while(currentNode != nullptr){
        Node * nextNode = currentNode->next
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

    // Create new node
    Node * newNode = new Node(newElement);
    if(newNode == nullptr){
        return false; // mem. allocation failed
    }

    // Edge case: No elements before
    if(head == nullptr || elementCount == 0){
        head = newNode;
        tail = newNode;
        elementCount++;
        return true;
    }

    // General case
    tail->next = newNode;
    tail = newNode;
    elementCount++;
    return true;
}

// Description: Inserts "newElement" at the front of the List 
//              and returns "true" if successful, "false" otherwise.
// Time Efficicency: O(1)
bool List::prepend( int newElement ){

    // Create new node
    Node * newNode = new Node(newElement);
    if(newNode == nullptr){
        return false;
    }

    // Edge case: No elements before
    if(head == nullptr || elementCount == 0){
        head = newNode;
        tail = newNode;
        elementCount++;
        return true;
    }

    // General case
    newNode->next = head;
    head = newNode;
    elementCount++;
    return true;
}

// Description: Removes the element from the front of the List 
//              and returns "true" if successful, "false" otherwise. 
// Precondition: List is not empty.
// Time Efficicency: O(1)
bool List::removeAtFront( ){

    // Check precondition
    if(head = nullptr || elementCount == 0){
        return false;
    }

    Node * currentHead = head;
    head = currentHead->next;
    delete currentHead;
    
    // Case: We removed the last element(front element)
    if(head == nullptr){
        tail = nullptr;
    }

    elementCount++;
    return true;
}

// Description: Returns via the parameter "frontElement" the element 
//              at the front of the List and returns "true" if 
//              successful, "false" otherwise. 
// Precondition: List is not empty.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
bool List::getFrontElement( int * frontElement ) const {

    // check pre condition
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
    cout << "This LIst has " << elementCount << " elements: { ";
    Node * currentNode = head;
    while(currentNode != nullptr){
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << "}" << endl;

}




bool List::insertAt(int position, int newElement) {
    if (position < 1 || position > elementCount + 1)
        return false;

    Node* newNode = new Node(newElement);
    if (newNode == nullptr)
        return false;

    // Insert at front
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        if (elementCount == 0) {
            tail = newNode;  // update tail if list was empty
        }
        elementCount++;
        return true;
    }

    // Insert at end
    if (position == elementCount + 1) {
        tail->next = newNode;
        tail = newNode;
        elementCount++;
        return true;
    }

    // General case (middle insert)
    Node* currentNode = head;
    for (int i = 1; i < position - 1; i++) {
        currentNode = currentNode->next;
    }

    newNode->next = currentNode->next;  // ✅ FIX: previously you used nextNode->next which caused skipping
    currentNode->next = newNode;

    elementCount++;
    return true;
}


bool List::removeAt(int position){

    if(position < 1 || position > elementCount)
        return false;

    if(position == 1){
        Node * currentNode = head;
        head = currentNode->next;
        delete currentNode;
        elementCount--;

        if(elementCount == 0){
            head = nullptr;
            tail = nullptr;
        }
        return true;
    }

    Node * currentNode = head;
    for(int i = 1; i < position - 1; i++){
        currentNode = currentNode->next;
    }

    Node * tobeRemoved = currentNode->next;
    currentNode->next = tobeRemoved->next;
    delete tobeRemoved;

    if(currentNode->next == nullptr){
        tail = currentNode;
    }

    elementCount--;
    return true;
}