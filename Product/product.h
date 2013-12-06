// product.h
// Class that stores and displays product information such as name, barcode
// and price.

#include <iostream>
#include <cstdlib>
#include <cstdint>

#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
  friend std::ostream &operator<<( std::ostream &, const Product & );
public:
  Product(); // default constructor; // initialize #, 0x00000000, 0.0
  Product(const char *, uint32_t, float); // 3-arg constructor
  ~Product();
  Product (const Product &); // copy constructor
  const Product &operator=(const Product &); // assignment overloader
  void SetName( const char* ); // sets the name field
  void SetBarCode( uint32_t ); // sets the bar code field
  void SetCost( float ); // sets the cost field
  const char *GetName() const; // returns a const pointer to the name field
  uint32_t GetBarCode() const; // returns the bar code by value
  float GetCost() const; // returns cost by value

private:
  char * name_; // product name
  uint32_t code_; // product bar code
  float cost_; // product cost
};

#endif