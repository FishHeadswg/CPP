/*
11/3/13
Trevor Richardson
*/

#ifndef COMPARE_SPY_H
#define COMPARE_SPY_H

namespace fsu
{
  template < typename T >
  class LessThanSpy
  {
  public:
    // def constructor initialize count to 0
    LessThanSpy() : count_(0)
    {}

    // () overload
    bool operator() (const T& t1, const T& t2)
    {
      ++count_;
      return (t1 < t2);
    }

    // reset count
    void Reset()
    {
      count_ = 0;
    }

    // return count
    size_t Count() const
    {
      return count_;
    }
  private:
    size_t  count_; // counts # of times operator() is called
  }; // end LessThanSpy class
} // end fsu namespace

#endif