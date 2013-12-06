/***********************
Trevor Richardson
bubbleSort.h
***********************/

#ifndef BUBBLE_T
#define BUBBLE_T

#include <vector>

class BubbleSort
{
private:
  std::vector< int > myVector; // Defines  vector
public:
	BubbleSort(const int myArray[], const size_t arraySize);
  void sortVector(); // Bubble sorts the vector and outputs result
};

#endif