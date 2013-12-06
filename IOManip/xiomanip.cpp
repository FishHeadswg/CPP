/*
xiomanip.cpp
11-11-13
Trevor Richardson

Implementations for I/O manipulators using ios::.
Explicitly sets and unsets all applicable formatting in each function.

*/

#include <xiomanip.h>

// Fillers
static const char
customFiller = '0',
defaultFiller = ' ';

// Manipulator implemenatations
std::ios& fsu::hex(std::ios& s)
{
  s.setf(std::ios::hex, std::ios::basefield);
  s.unsetf(std::ios::uppercase | std::ios::showbase);
  s.fill(defaultFiller);
  return s;
}
std::ios& fsu::Hex(std::ios& s)
{
  s.setf(std::ios::hex, std::ios::basefield);
  s.setf(std::ios::uppercase);
  s.unsetf(std::ios::showbase);
  s.fill(defaultFiller);
  return s;
}
std::ios& fsu::hexFill(std::ios& s)
{
  s.setf(std::ios::hex, std::ios::basefield);
  s.unsetf(std::ios::uppercase | std::ios::showbase);
  s.fill(customFiller);
  return s;
}
std::ios& fsu::HexFill(std::ios& s)
{
  s.setf(std::ios::hex, std::ios::basefield);
  s.setf(std::ios::uppercase);
  s.unsetf(std::ios::showbase);
  s.fill(customFiller);
  return s;
}
std::ios& fsu::hexShowBase(std::ios& s)
{
  s.setf(std::ios::hex, std::ios::basefield);
  s.unsetf(std::ios::uppercase);
  s.setf(std::ios::showbase);
  s.fill(defaultFiller);
  return s;
}
std::ios& fsu::HexShowBase(std::ios& s)
{
  s.setf(std::ios::hex, std::ios::basefield);
  s.setf(std::ios::uppercase);
  s.setf(std::ios::showbase);
  s.fill(defaultFiller);
  return s;
}
std::ios& fsu::oct(std::ios& s)
{
  s.setf(std::ios::oct, std::ios::basefield);
  s.unsetf(std::ios::uppercase | std::ios::showbase);
  s.fill(defaultFiller);
  return s;
}
std::ios& fsu::octFill(std::ios& s)
{
  s.setf(std::ios::oct, std::ios::basefield);
  s.unsetf(std::ios::uppercase | std::ios::showbase);
  s.fill(customFiller);
  return s;
}
std::ios& fsu::octShowBase(std::ios& s)
{
  s.setf(std::ios::oct, std::ios::basefield);
  s.unsetf(std::ios::uppercase);
  s.setf(std::ios::showbase);
  s.fill(defaultFiller);
  return s;
}
std::ios& fsu::dec(std::ios& s)
{
  s.setf(std::ios::dec, std::ios::basefield);
  s.unsetf(std::ios::uppercase | std::ios::showbase);
  s.fill(defaultFiller);
  return s;
}