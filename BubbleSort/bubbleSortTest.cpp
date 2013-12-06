/***********************
Trevor Richardson
bubbleSortTest.cpp
***********************/
////bubbleSortTest.cpp

#include "bubbleSort.h"

int main()
{
    const size_t arraySize = 10; // size of array a
    int myArray[ arraySize ] = { 37, 89, 12, 8, 10, 4, 6, 68, 45, 2 };
    BubbleSort bubble(myArray, arraySize);
    bubble.sortVector();
} // end main