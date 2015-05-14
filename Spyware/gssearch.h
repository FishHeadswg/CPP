/*
11/3/13
Trevor Richardson
*/

#ifndef GSSEARCH_H
#define GSSEARCH_H

#include <compare_spy.h> // LessThanSpy<T> predicate

namespace seq
{
  // return upper bound of T
  template < class I, typename T, class P >
  I g_lower_bound(I beg, I end, const T& val, P& cmp)
  {
    while (beg != end)
    {
      if (!cmp(*beg, val)) // if current itr is NOT < val
        return beg; // return current itr
      ++beg;
    }
    return beg; // return end itr
  }

  // return upper bound of T
  template < class I, typename T, class P>
  I g_upper_bound(I beg, I end, const T& val, P& cmp)
  {
    while (beg != end)
    {
      if (cmp(val, *beg)) // if val < current itr (3 < 5)
        return beg; // return current itr
      ++beg;
    }
    return beg; // return end itr
  }
} // end seq namespace

#endif