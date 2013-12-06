// stats.h
// Provides functions to find the mean of a set of numbers
// and to sort the numbers to find the median.
#ifndef STATS_H
#define STATS_H

float Mean   (const int* array, size_t size); // calculates mean of data in array
float Median (int* array, size_t size);       // calculates median of data in array
void  Sort   (int* array, size_t size);       // sorts the data in array

#endif