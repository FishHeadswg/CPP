// uintset.h
// Trevor Richardson
// Created 08/01/13
// UIntSet class that creates, manipulates, and displays unsigned integer sets
// using the BitVector class's API

#ifndef UINTSET_H
#define UINTSET_H

#include <iostream>
#include <bitvect.h>

class UIntSet
{
public:
  UIntSet ( size_t range = 64 ); // Constructor, default range = 64
  UIntSet ( const UIntSet& ); // Copy constructor

  void Insert ( size_t n ); // inserts n into set
  void Remove ( size_t n ); // removes n from set
  void Clear (); // makes set empty
  bool Member ( size_t n ) const;  // returns true iff n is in set

  bool Empty () const; // true iff set is empty
  size_t Size () const; // returns number of elements in set
  size_t Range () const; // returns upper bound of range/universe

  UIntSet& operator=  (const UIntSet& s);  // set = s (assignment operator)
  UIntSet& operator+= (const UIntSet& s);  // set = set union s
  UIntSet& operator*= (const UIntSet& s);  // set = set intersection s
  UIntSet& operator-= (const UIntSet& s);  // set = set difference s

  void Dump ( std::ostream& os ) const;
private:
  fsu::BitVector bv_; // bit vector representing set
};

UIntSet operator+  (const UIntSet& s1, const UIntSet& s2);  //  s1 union s2
UIntSet operator*  (const UIntSet& s1, const UIntSet& s2);  //  s1 intersect s2
UIntSet operator-  (const UIntSet& s1, const UIntSet& s2);  //  s1 diff s2
bool    operator== (const UIntSet& s1, const UIntSet& s2);  // true iff equal
bool    operator!= (const UIntSet& s1, const UIntSet& s2);  // true iff not ==l
std::ostream& operator<< (std::ostream& os, const UIntSet& s); // output

#endif
