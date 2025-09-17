/*
 * testDriver.cpp
 * 
 * Class Description: Tests the List data collection class.
 *
 * Modified on: July 2025
 * Author: AL 
 */

#include <cstddef>  // Needed for nullptr
#include <iostream>
#include "List.h"                

using std::cout;
using std::endl;

int main() {

  /* Variables declaration */
  const unsigned int MIN_NUMBER_OF_ELEMENTS = 5;
  unsigned int minValPosition; 
  /* Please, see the note in the method insert(...) in List.cpp (Lab 7 Solution) about "new(std::nothrow)". */
  List * aList  = new(std::nothrow) List( );   
  if ( aList == nullptr ) 
    return 1;

  /* Populating the list */
  cout << "Populating the List." << endl;  
  srand( time( 0 ) );
  unsigned int limit = MIN_NUMBER_OF_ELEMENTS;
  for ( unsigned int i = 0; i < limit; i++ )
    if ( ! aList->append( rand( ) % 100 ) ) 
      cout << "Could not aList->append( )." << endl; 
  
  /* Printing the List */ 
  cout << "Printing the List with " << aList->getElementCount( ) << " elements." << endl; 
  aList->printList( );   


  aList->findMin(&minValPosition);
  cout << "Min position is: " << minValPosition << endl;
  
  delete aList;
  aList = NULL;
  
  return 0;
}
