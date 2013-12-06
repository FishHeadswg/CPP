/***********************
Trevor Richardson
bubbleSort.cpp
***********************/
//bubbleSort.cpp

#include <iostream>
#include <iomanip>
#include "bubbleSort.h"

// Constructor, takes in array + array's size, constructs the unsorted vector
BubbleSort::BubbleSort(const int myArray[], const size_t arraySize)
{
  // copy array to vector using back_inserter iterator rather than .begin()
  std::copy(&myArray[0], &myArray[arraySize], back_inserter(myVector));
  std::cout << "Data items in original order\n";
  // output original vector
  std::vector<int>::const_iterator constIterator = myVector.begin();
  for ( ; constIterator != myVector.end(); ++constIterator )
    std::cout << std::setw( 4 ) << *constIterator; 
} // end constructor

void BubbleSort::sortVector()    // bubble sort
    // loop to control number of passes
    /* loop for one iteration less than the size of the array */
{
  for ( size_t i = 0, d = 1; i < (myVector.size() - d); ++i )
    {
        /* loop to control number of comparisons per pass
        iterate j from 0 and keep looping while j is less than arraySize - 1 */
      for (size_t j = 0; j < (myVector.size() - d); ++j)
            /* compare side-by-side elements and 
            swap them if first element is greater than second element
            test if element j is greater than element j + 1 */
          if (myVector[j] > myVector[j+1])
            {
                /* swap the values in element j and element j + 1
                using hold as temporary storage */
              int hold = myVector[j+1];
              myVector[j+1] = myVector[j];
              myVector[j] = hold;
            } // end if
  } // end for

    std::cout << "\nData items in ascending order\n";

    // output sorted array
    for ( size_t k = 0; k < myVector.size(); ++k )
      std::cout << std::setw( 4 ) << myVector[ k ];

    std::cout << std::endl; // end bubbleSort
}