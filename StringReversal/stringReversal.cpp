/***********************
Trevor Richardson
stringReversal.cpp
***********************/

#include <iostream>
#include <cstdlib>
#include <cstring>

void swap(char *, char *); // swap proto

int main()
{
  char myStr[80];
  char *head = NULL, *tail = NULL;

  std::cout << "Enter a string less than 80 characters long." << std::endl;
  std::cin.getline(myStr,80);

  // Assign myStr to both head and tail
  head = myStr;
  tail = &myStr[strlen(myStr)-1];

  // while loop to reverse the string
  // Loops until the head value passes or equals the middle value
  while (!(head >= tail))
  {
      swap(head, tail); // swaps values
      ++head;
      --tail;
  } // end while
  std::cout << "Your string reversed is :" << myStr << std::endl;
} // end main

void swap(char *head, char *tail) // swaps tail and head values
{
  char hold = *head;
  *head = *tail;
  *tail = hold;
}
