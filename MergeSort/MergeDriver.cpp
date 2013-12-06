// MergeSort test program
#include <iostream>
#include "MergeSort.h" // class MergeSort definition
using namespace std;

int main()
{
   // create object to perform merge sort
   MergeSort sortVector( 10 );
      
   cout << "Unsorted vector:" << endl;
   sortVector.displayElements(); // print unsorted vector
   cout << endl << endl;
 
   sortVector.sort(); // sort vector

   cout << "Sorted vector:" << endl;
   sortVector.displayElements(); // print sorted vector
   cout << endl;
} // end main
