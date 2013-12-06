// MergeSort.h
// Class that creates a vector filled with random integers.  
// Provides a function to sort the vector with merge sort.
#include <vector>
using namespace std;

// MergeSort class definition
class MergeSort
{
public:
   MergeSort( int ); // constructor initializes vector
   void sort(); // sort vector using merge sort
   void displayElements() const; // display vector elements
private:
   int size; // vector size
   vector< int > data; // vector of ints
   void sortSubVector( int, int ); // sort subvector
   void merge( int, int, int, int ); // merge two sorted vectors
   void displaySubVector( int, int ) const; // display subvector
}; // end class SelectionSort
