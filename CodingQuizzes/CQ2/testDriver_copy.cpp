/*
 * testDriver.cpp
 * 
 * Class Description: Tests the List data collection class.
 *
 * Modified on: July 2025
 * Author: AL + GPT Enhanced
 */

#include <cstddef>  
#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include "List.h"                

using std::cout;
using std::endl;

int main() {
    /* Setup */
    List* aList = new List();
    srand(time(0));

    // ---------- INSERT TESTING ----------
    cout << "🧪 Inserting elements...\n";
    for (unsigned int i = 1; i <= 5; i++) {
        int element = rand() % 100;
        if (!aList->insert(i, element)) {
            cout << "❌ Failed to insert " << element << " at position " << i << endl;
        } else {
            cout << "✅ Inserted " << element << " at position " << i << endl;
        }
    }

    // Invalid insert
    cout << "\n🧪 Trying invalid insert at position 0...\n";
    if (!aList->insert(0, 123)) {
        cout << "✅ Correctly failed insert at invalid position 0\n";
    }

    // Insert in the middle
    cout << "\n🧪 Insert in middle (position 3)...\n";
    aList->insert(3, 888);

    // ---------- PRINTING ----------
    cout << "\n📋 Current List:\n";
    aList->printList();

    // ---------- REMOVE TESTING ----------
    cout << "\n🧪 Removing head (position 1)...\n";
    aList->remove(1);
    aList->printList();

    cout << "🧪 Removing tail (last position)...\n";
    aList->remove(aList->getElementCount());
    aList->printList();

    cout << "🧪 Removing invalid position 99...\n";
    if (!aList->remove(99)) {
        cout << "✅ Correctly rejected invalid removal\n";
    }

    cout << "\n📋 List after removals:\n";
    aList->printList();

    // ---------- GETELEMENT TESTING ----------
    cout << "\n🧪 Testing getElement()\n";
    int retrieved;
    if (aList->getElement(2, &retrieved)) {
        cout << "✅ Got element at position 2: " << retrieved << endl;
    } else {
        cout << "❌ Failed to get element at position 2\n";
    }

    if (!aList->getElement(99, &retrieved)) {
        cout << "✅ Correctly rejected getElement at invalid position 99\n";
    }

    // ---------- SETELEMENT TESTING ----------
    cout << "\n🧪 Testing setElement()\n";
    if (aList->setElement(2, 777)) {
        cout << "✅ Updated element at position 2 to 777\n";
    } else {
        cout << "❌ Failed to set element at position 2\n";
    }

    if (!aList->setElement(99, 555)) {
        cout << "✅ Correctly rejected setElement at invalid position 99\n";
    }

    // Final print
    cout << "\n📋 Final List:\n";
    aList->printList();

    // ---------- ELEMENT COUNT ----------
    cout << "\n📊 Final element count: " << aList->getElementCount() << endl;

    // Clean up
    delete aList;
    aList = nullptr;

    cout << "\n✅ All tests complete.\n";
    return 0;
}
