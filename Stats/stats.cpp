// stats.cpp
// Implementation of Mean, Median, and Sort functions.

#include <iostream>
#include "stats.h"

float Mean (const int* array, size_t size)
{
  float total = 0;
  for ( unsigned i = 0; i < size; ++i)
    total += array[i];
  return (total / size);

}
float Median (int* a, size_t size)
{
  Sort(a, size);
  if ( ( size % 2 ) == 1 )
    return static_cast< float >(a[(( size + 1 ) / 2) - 1]);
  else
  {
    float first = static_cast< float >(a[(size / 2)]);
    float second = static_cast< float >(a[(size / 2) - 1]);
    return (first + second) / 2;
  }
}

void Sort (int* a, size_t size)
{
  for ( unsigned i = 1; i < size ; ++i)
  {
    int currentValue = a[i];
    int element = i;
    while (element > 0 && currentValue < a[element - 1])
    {
      a[element] = a[element - 1];
      --element;
    }
    a[element] = currentValue;
  }
}