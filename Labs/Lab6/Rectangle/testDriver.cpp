/* Driver program for testing the Rectangle class. */
#include <iostream> // As we need to print data
#include "Rectangle.h"
using namespace std;

int main() {
  /* Test case 1: Rectangle width = 5, height = 7 */
  Rectangle R1 = Rectangle(5,7);          // On the stack
  
  /* Test case 2: Rectangle width = 5, height = 5 */
  Rectangle * ptrR2 = new Rectangle(5,5); // On the heap
  
  /* Test case 3: Rectangle width = 0, height = 6 */
  Rectangle * ptrR3 = new Rectangle(0,6); // On the heap
  
  cout << "Calling R1.printRectangle() " << endl;
  R1.printRectangle();
  
  cout << "Calling ptrR2->printRectangle() " << endl;
  ptrR2->printRectangle();  
  
  cout << "Calling ptrR3->printRectangle() " << endl;  
  ptrR3->printRectangle();
  
  // Test computeArea()
  cout << "\nR1 area: " << R1.computeArea() << endl;
  cout << "ptrR2 area: " << ptrR2->computeArea() << endl;
  
  // Test computePerimeter()
  cout << "R1 perimeter: " << R1.computePerimeter() << endl;
  cout << "ptrR3 perimeter: " << ptrR3->computePerimeter() << endl;
  
  // Test isRectangleSquare()
  cout << "Is ptrR2 a square? " << (ptrR2->isRectangleSquare() ? "Yes" : "No") << endl;
  
  // Release heap memory  
  delete ptrR2;
  ptrR2 = NULL;
  
  delete ptrR3;
  ptrR3 = NULL;
  
  return 0;
}