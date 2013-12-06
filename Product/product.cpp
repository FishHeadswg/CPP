// product.cpp
// Implementations for Product class member functions & left-shift overloader


#include <product.h>
#include <cstring>
#include <iomanip>

Product::Product() // default constructor; // initialize #, 0x00000000, 0.0
 : name_(0), code_(0x00000000), cost_(0.0)
{
  name_ = new char [2];
  name_[0] = '#';
  name_[1] = '\0';
}

Product::Product(const char * name, uint32_t code, float cost) // 3-arg constr
: name_(0), code_(code), cost_(cost)
{
  size_t size = strlen( name );
  name_ = new char [size + 1];
  name_[-1] = '\0';
  strcpy(name_, name);
}

Product::~Product()
{
  if (name_ != 0)
    delete [] name_;
}

Product::Product (const Product &productToCopy) // copy constructor
: name_(0), code_(productToCopy.code_), cost_(productToCopy.cost_)
{
  size_t size = strlen( productToCopy.name_ );
  name_ = new char [size + 1];
  name_[-1] = '\0';
  strcpy(name_, productToCopy.name_);
}

const Product &Product::operator=(const Product &product) // assign overloader
{
  if (&product != this)
  {
    if ( name_ != 0 )
      delete [] name_;
    size_t size = strlen( product.name_ );
    name_ = new char [size + 1];
    name_[-1] = '\0';
    strcpy(name_, product.name_);
    code_ = product.code_;
    cost_ = product.cost_;
  }
  return *this;
}

void Product::SetName( const char* name ) // sets the name field
{
  if ( name_ != 0 )
    delete [] name_;
  size_t size = strlen( name );
  name_ = new char [size + 1];
  name_[-1] = '\0';
  strcpy(name_, name);
}

void Product::SetBarCode( uint32_t code) // sets the bar code field
{
  code_ = code;
}

void Product::SetCost( float cost ) // sets the cost field
{
  cost_ = cost;
}

const char* Product::GetName() const // returns const pointer to the name field
{
  return name_;
}

uint32_t Product::GetBarCode() const // returns the bar code by value
{
  return code_;
}

float Product::GetCost() const // returns cost by value
{
  return cost_;
}

std::ostream &operator<<( std::ostream &os, const Product &product )
{
  os << product.name_ << '\t'
    << std::hex << std::fixed << std::setfill( '0' ) << std::setw( 8 ) 
    << std::uppercase << product.code_ << '\t'
    << std::dec << std::showpoint << std::setprecision(2) << product.cost_;
  return os;
}
