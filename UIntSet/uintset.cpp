// uintset.h
// Trevor Richardson
// Implementation of UIntSet

#include <uintset.h>

UIntSet::UIntSet ( size_t range ) // Constructor, default range = 64
: bv_(range)
{}

UIntSet::UIntSet ( const UIntSet &set ) // Copy constructor
: bv_(set.bv_)
{}

void UIntSet::Insert ( size_t num ) // inserts num into set
{
  bv_.Set(num);
}

void UIntSet::Remove ( size_t num ) // removes num from set
{
  bv_.Unset(num);
}

void UIntSet::Clear () // makes set empty
{
  bv_.Unset();
}

bool UIntSet::Member ( size_t num ) const // returns true iff num is in set
{
  return bv_.Test(num);
}

bool UIntSet::Empty () const // true iff set is empty
{
  for ( size_t i = 0; i < Range(); ++i)
    if ( Member(i) )
      return false;
  return true;
}

size_t UIntSet::Size () const // returns number of elements in set
{
  size_t size = 0;
  for ( size_t i = 0; i < Range(); ++i)
    if ( Member(i) )
      ++size;
  return size;
}

size_t UIntSet::Range () const // returns upper bound of range/universe [0,ub)
{
  return bv_.Size();
}

UIntSet& UIntSet::operator=  (const UIntSet& s)  // assignment operator
{
  if ( this != &s )
    bv_ = s.bv_;
  return *this;
}

UIntSet& UIntSet::operator+= (const UIntSet& s)  // set = set union s
{
  for ( size_t i = 0; i < Range(); ++i)
  {
    if ( s.Member(i) )
      Insert(i);
  }
  return *this;
}

UIntSet& UIntSet::operator*= (const UIntSet& s)  // set = set intersection s
{
  for ( size_t i = 0; i < Range(); ++i)
  {
    if ( s.Member(i) & Member(i) )
      Insert(i);
    else
      Remove(i);
  }
  return *this;
}

UIntSet& UIntSet::operator-= (const UIntSet& s)  // set = set difference s
{
  for (size_t i = 0; i < Range(); ++i)
  {
    if ( s.Member(i) )
      Remove(i);
  }
  return *this;
}

void UIntSet::Dump ( std::ostream& os ) const
{
  bv_.Dump( os );
}

UIntSet operator+ (const UIntSet& s1, const UIntSet& s2)  //  s1 union s2
{
  UIntSet s(s1);
  s += s2;
  return s;
}

UIntSet operator* (const UIntSet& s1, const UIntSet& s2)  //  s1 intersect s2
{
  UIntSet s(s1);
  s *= s2;
  return s;
}

UIntSet operator- (const UIntSet& s1, const UIntSet& s2)  // s1 difference s2
{
  UIntSet s(s1);
  s -= s2;
  return s;
}

bool operator== (const UIntSet& s1, const UIntSet& s2)  // equal as sets
{
  size_t range;
  if ( s1.Range() > s2.Range() )
    range = s1.Range();
  else
    range = s2.Range();
  for ( size_t i = 0; i < range; ++i )
  {
    if ( s1.Member(i) != s2.Member(i) )
      return false;
  }
  return true;
}

bool operator!= (const UIntSet& s1, const UIntSet& s2)  // not equal as sets
{
  return !(operator==( s1, s2 ));
}

std::ostream& operator<< (std::ostream& os, const UIntSet& s) // output
{
  os << "{ ";
  for ( size_t i = 0; i < s.Range(); ++i)
  {
    if ( s.Member(i) )
      os << i << " ";
  }
  os << "}";
  return os;
}
