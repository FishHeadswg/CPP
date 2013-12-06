/*
xiomanip.h
11-11-13
Trevor Richardson

Prototypes for I/O manipulators using ios::

*/

#ifndef XIOMANIP_H
#define XIOMANIP_H

#include <ios>

namespace fsu
{
  std::ios& hex(std::ios& os);
  std::ios& Hex(std::ios& os);
  std::ios& hexFill(std::ios& os);
  std::ios& HexFill(std::ios& os);
  std::ios& hexShowBase(std::ios& os);
  std::ios& HexShowBase(std::ios& os);
  std::ios& oct(std::ios& os);
  std::ios& octFill(std::ios& os);
  std::ios& octShowBase(std::ios& os);
  std::ios& dec(std::ios& os);
}

#endif