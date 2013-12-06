// main.cpp
// Driver for Stats functions
#include <iostream>
#include "stats.h"

using std::cout;
using std::cin;

int main()
{
  int num;
  int a[ 100 ];
  cout << "Enter integers ('x' to quit):\n";
  int dataSize = 0;
  for (int k = 0; cin >> num && k < 100; ++k)
  {
    a[k] = num;
    ++dataSize;
  }
  cout << "\nData as entered: ";
  for (int m = 0; m < dataSize; ++m)
    cout << a[m] << " ";
  cout << "\nMean:   " << Mean(a, dataSize);
  cout << "\nMedian: " << Median(a, dataSize);
  cout << "\nData after sort: ";
  for (int m = 0; m < dataSize; ++m)
    cout << a[m] << " ";
}