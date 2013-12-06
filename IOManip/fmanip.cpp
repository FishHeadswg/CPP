/*
  fmanip.cpp
  Chris Lacher
  10/24/13

  testing the fsu I/O manipulators (unsigned integers)

    hex         hexadecomal, lower case, no fill
    Hex         hexadecomal, upper case, no fill
    hexFill     hexadecomal, lower case, fill
    HexFill     hexadecomal, upper case, fill
    hexShowBase hexadecomal, lower case, no fill, show base
    HexShowBase hexadecomal, upper case, no fill, show base

    oct         octal, no fill
    octFill     octal, fill
    octShowBase octal, no fill, show base

    dec         decimal, no fill, no show base [default settings]

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <xiomanip.h>

int main()
{
  unsigned long n;
  std::cout << "Enter unsigned integer ('x' to quit): ";
  while (std::cin >> n)
  {
    std::cout << "  input:            "                     << std::setw(16) << n << '\n'
              << "  fsu::dec:         " << fsu::dec         << std::setw(16) << n << '\n'
              << "  fsu::hex:         " << fsu::hex         << std::setw(16) << n << '\n'
              << "  fsu::Hex:         " << fsu::Hex         << std::setw(16) << n << '\n'
              << "  fsu::hexFill:     " << fsu::hexFill     << std::setw(16) << n << '\n'
              << "  fsu::HexFill:     " << fsu::HexFill     << std::setw(16) << n << '\n'
              << "  fsu::hexShowBase: " << fsu::hexShowBase << std::setw(16) << n << '\n'
              << "  fsu::HexShowBase: " << fsu::HexShowBase << std::setw(16) << n << '\n'
              << "  fsu::oct:         " << fsu::oct         << std::setw(16) << n << '\n'
              << "  fsu::octFill:     " << fsu::octFill     << std::setw(16) << n << '\n'
              << "  fsu::octShowBase: " << fsu::octShowBase << std::setw(16) << n << '\n'
              << "  fsu::dec:         " << fsu::dec         << std::setw(16) << n << '\n';
    std::cout << "Enter unsigned integer ('x' to quit): ";
  }
}
