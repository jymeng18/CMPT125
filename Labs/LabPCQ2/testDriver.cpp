/*
 * testDriver.cpp
 *
 * Class Description: Driver program to test the List data collection class.
 *
 * Author: AL
 * Updated: August 2025
 */

#include <iostream>
#include <ctime>        // For time()
#include <cstdlib>      // For rand(), srand()
#include <new>          // For std::nothrow
#include "List.h"

using std::cout;
using std::endl;

int main() {
    const unsigned int MIN_NUMBER_OF_ELEMENTS = 5;
    List* aList = new(std::nothrow) List();

    if (aList == nullptr) {
        cout << "Memory allocation failed for List." << endl;
        return 1;
    }

    int theFrontElement = 0;
    int newElement = 0;

    // ================================
    // Section 1: Populate List
    // ================================
    cout << ">> Populating the List..." << endl;
    srand(static_cast<unsigned int>(time(0)));
    unsigned int limit = MIN_NUMBER_OF_ELEMENTS + rand() % 10;

    for (unsigned int i = 0; i < limit; i++) {
        // Append test
        newElement = rand() % 10;
        cout << "[Append] aList->append(" << newElement << ")" << endl;
        if (!aList->append(newElement))
            cout << "Append failed." << endl;

        cout << "List after append (" << aList->getElementCount() << " elements):" << endl;
        aList->printList();

        // Prepend test
        newElement = rand() % 10;
        cout << "[Prepend] aList->prepend(" << newElement << ")" << endl;
        if (!aList->prepend(newElement))
            cout << "Prepend failed." << endl;

        cout << "List after prepend (" << aList->getElementCount() << " elements):" << endl;
        aList->printList();
    }

    // ================================
    // Section 2: Get Front Element
    // ================================
    cout << "\n>> Getting the front element..." << endl;
    if (aList->getFrontElement(&theFrontElement))
        cout << "Front element is: " << theFrontElement << endl;
    else
        cout << "getFrontElement failed." << endl;

    // ================================
    // Section 3: Remove Front Element
    // ================================
    cout << "\n>> Removing front element..." << endl;
    if (!aList->removeAtFront())
        cout << "removeAtFront failed." << endl;

    cout << "List after removing front (" << aList->getElementCount() << " elements):" << endl;
    aList->printList();

    // ================================
    // Section 4: Get Front Again
    // ================================
    cout << "\n>> Getting the front element again..." << endl;
    if (aList->getFrontElement(&theFrontElement))
        cout << "New front element is: " << theFrontElement << endl;
    else
        cout << "getFrontElement failed." << endl;

    // ================================
    // Section 5: Clean Up (Don't delete will need)
    // ================================
    delete aList;
    aList = nullptr;

    cout << "\n>> Test complete. Memory cleaned up." << endl;
    return 0;
}
