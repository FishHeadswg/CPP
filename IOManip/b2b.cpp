/*
b2b.cpp
11-11-13
Trevor Richardson

Takes input file with dec, hex, or oct input 
and converts it into oct, hex, or dec with specified formatting. 
Permits conversion to and from the same base, e.g. DDF, HhB, Oon.

*/

#include <iostream>
#include <fstream>
#include <iomanip>    // std::setw
#include <xiomanip.h> // fsu::hex, fsu::hexShowBase, fsu::hexFill, ...

static const unsigned short
cwh = 16, // max digits of unsigned long hexadecimal
cwd = 20, // max digits of unsigned long decimal
cwo = 26, // max digits of unsigned long octal
cs1 = 4, cs2 = 2; // col spacers

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    std::cerr << "Incorrect number of arguments: two expected\n"
      "Please enter command followed by two (2) filenames\n"
      "Example: \"b2b.x inputfilename outfilename\n";
    exit(1);
  }
  char *inFile = argv[1];
  char *outFile = argv[2];
  std::ifstream ifs;
  std::ofstream ofs;
  ifs.open(inFile);
  if (!inFile)
  {
    std::cerr << "Unable to open input file: " << inFile << "\n";
    exit(1);
  }
  ofs.open(outFile);
  if (!outFile)
  {
    std::cerr << "Unable to open output file: " << outFile << "\n";
    exit(1);
  }
  ofs << "Name of this file:       " << outFile << '\n';
  ofs << "Name of input data file: " << inFile << '\n' << '\n';
  char format[4]; // Input/Output formatting
  bool formatted = false;  // Format has been read and stored
  unsigned long num; // Input numbers
  const int maxLine = 256; // Maximum allowed length for documentation lines
  char c;

  // Skips documentation and gets formatting
  while ((c = ifs.peek()) && (ifs.peek() != EOF) && (formatted == false))
  {
    switch (c)
    {
    case '#':
      ifs.ignore(maxLine, '\n');
      break;
    case '\n':
      ifs.get();
      break;
    case 'o':
    case 'O':
      ifs >> format;
      ifs >> fsu::oct; // Input set to oct formatting
      formatted = true;
      break;
    case 'h':
      ifs >> format;
      ifs >> fsu::hex; // Input set to hex formatting
      formatted = true;
      break;
    case 'H':
      ifs >> format;
      ifs >> fsu::Hex; // Input set to Hex formatting
      formatted = true;
      break;
    case 'd':
    case 'D':
      ifs >> format;
      ifs >> fsu::dec; // Input set to dec formatting
      formatted = true;
      break;
    default:
      ifs.get();
      break;
    }
  }

  // Formatting cases

  // **Input DECIMAL** [dD][?][?]
  if (format[0] == 'd' || format[0] == 'D')
  {
    // [dD][dD][ANY]
    if (format[1] == 'd' || format[1] == 'D')
    {
      // Table header
      ofs << std::setw(cwd + cs1) << "dec" << std::setw(cs2)
        << " " << std::setw(cwd) << "dec" << '\n';
      // Outputs numbers in table according to formatting
      while (ifs >> num)
      {
        ofs << std::setw(cwd + cs1) << fsu::dec << num <<
          std::setw(cs2) << "  " << std::setw(cwd) << num << '\n';
      }
    }
    // [dD][h][fF]
    if ((format[1] == 'h') 
      && (format[2] == 'f' || format[2] == 'F'))
    {
      ofs << std::setw(cwd + cs1) << "dec" << std::setw(cs2)
        << " " << std::setw(cwh) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwd + cs1) << fsu::dec << num << std::setw(cs2)
          << "  " << std::setw(cwh) << fsu::hexFill << num << '\n';
      }
    }
    // [dD][h][nN]
    if ((format[1] == 'h') 
      && (format[2] == 'n' || format[2] == 'N'))
    {
      ofs << std::setw(cwd + cs1) << "dec" << std::setw(cs2)
        << " " << std::setw(cwh) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwd + cs1) << fsu::dec << num << std::setw(cs2)
          << "  " << std::setw(cwh) << fsu::hex << num << '\n';
      }
    }
    // [dD][h][bB]
    if ((format[1] == 'h') 
      && (format[2] == 'b' || format[2] == 'B'))
    {
      ofs << std::setw(cwd + cs1) << "dec" << std::setw(cs2)
        << " " << std::setw(cwh + 2) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwd + cs1) << fsu::dec << num << std::setw(cs2)
          << "  " << std::setw(cwh + 2) << fsu::hexShowBase << num << '\n';
      }
    }
    // [dD][H][bB]
    if ((format[1] == 'H') 
      && (format[2] == 'b' || format[2] == 'B'))
    {
      ofs << std::setw(cwd + cs1) << "dec" << std::setw(cs2)
        << " " << std::setw(cwh + 2) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwd + cs1) << fsu::dec << num << std::setw(cs2)
          << "  " << std::setw(cwh + 2) << fsu::HexShowBase << num << '\n';
      }
    }
    // [dD][H][nN]
    if ((format[1] == 'H') 
      && (format[2] == 'n' || format[2] == 'N'))
    {
      ofs << std::setw(cwd + cs1) << "dec" << std::setw(cs2)
        << " " << std::setw(cwh) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwd + cs1) << fsu::dec << num << std::setw(cs2)
          << "  " << std::setw(cwh) << fsu::Hex << num << '\n';
      }
    }
    // [dD][H][fF]
    if ((format[1] == 'H') 
      && (format[2] == 'f' || format[2] == 'F'))
    {
      ofs << std::setw(cwd + cs1) << "dec" << std::setw(cs2)
        << " " << std::setw(cwh) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwd + cs1) << fsu::dec << num << std::setw(cs2)
          << "  " << std::setw(cwh) << fsu::HexFill << num << '\n';
      }
    }
    // [dD][Oo][bB]
    if (((format[1] == 'o') || (format[1] == 'O')) 
      && (format[2] == 'b' || format[2] == 'B'))
    {
      ofs << std::setw(cwd + cs1) << "dec" << std::setw(cs2)
        << " " << std::setw(cwo + 1) << "oct" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwd + cs1) << fsu::dec << num << std::setw(cs2)
          << "  " << std::setw(cwo + 1) << fsu::octShowBase << num << '\n';
      }
    }
    // [dD][Oo][nN]
    if (((format[1] == 'o') || (format[1] == 'O'))
      && (format[2] == 'n' || format[2] == 'N'))
    {
      ofs << std::setw(cwd + cs1) << "dec" << std::setw(cs2)
        << " " << std::setw(cwo) << "oct" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwd + cs1) << fsu::dec << num << std::setw(cs2)
          << "  " << std::setw(cwo) << fsu::oct << num << '\n';
      }
    }
    // [dD][Oo][fF]
    if (((format[1] == 'o') || (format[1] == 'O'))
      && (format[2] == 'f' || format[2] == 'F'))
    {
      ofs << std::setw(cwd + cs1) << "dec" << std::setw(cs2)
        << " " << std::setw(cwo) << "oct" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwo + cs1) << fsu::dec << num << std::setw(cs2)
          << "  " << std::setw(cwo) << fsu::octFill << num << '\n';
      }
    }
  }

  // **Input OCTAL** [oO][?][?]
  if (format[0] == 'o' || format[0] == 'O')
  {
    // [oO][dD][ANY]
    if ((format[1] == 'd') || (format[1] == 'D'))
    {
      ofs << std::setw(cwo + cs1) << "oct" << std::setw(cs2)
        << " " << std::setw(cwd) << "dec" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwo + cs1) << fsu::oct << num << std::setw(cs2)
          << "  " << std::setw(cwd) << fsu::dec << num << '\n';
      }
    }
    // [oO][h][nN]
    if ((format[1] == 'h') 
      && (format[2] == 'n' || format[2] == 'N'))
    {
      ofs << std::setw(cwo + cs1) << "oct" << std::setw(cs2)
        << " " << std::setw(cwh) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwo + cs1) << fsu::oct << num << std::setw(cs2)
          << "  " << std::setw(cwh) << fsu::hex << num << '\n';
      }
    }
    // [oO][h][fF]
    if ((format[1] == 'h') 
      && (format[2] == 'f' || format[2] == 'F'))
    {
      ofs << std::setw(cwo + cs1) << "oct" << std::setw(cs2)
        << " " << std::setw(cwh) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwo + cs1) << fsu::oct << num << std::setw(cs2)
          << "  " << std::setw(cwh) << fsu::hexFill << num << '\n';
      }
    }
    // [oO][h][bB]
    if ((format[1] == 'h') 
      && (format[2] == 'b' || format[2] == 'B'))
    {
      ofs << std::setw(cwo + cs1) << "oct" << std::setw(cs2)
        << " " << std::setw(cwh + 2) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwo + cs1) << fsu::oct << num << std::setw(cs2)
          << "  " << std::setw(cwh + 2) << fsu::hexShowBase << num << '\n';
      }
    }
    // [oO][H][bB]
    if ((format[1] == 'H') 
      && (format[2] == 'b' || format[2] == 'B'))
    {
      ofs << std::setw(cwo + cs1) << "oct" << std::setw(cs2)
        << " " << std::setw(cwh + 2) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwo + cs1) << fsu::oct << num << std::setw(cs2)
          << "  " << std::setw(cwh + 2) << fsu::HexShowBase << num << '\n';
      }
    }
    // [oO][H][fF]
    if ((format[1] == 'H') 
      && (format[2] == 'f' || format[2] == 'F'))
    {
      ofs << std::setw(cwo + cs1) << "oct" << std::setw(cs2)
        << " " << std::setw(cwh) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwo + cs1) << fsu::oct << num << std::setw(cs2)
          << "  " << std::setw(cwh) << fsu::HexFill << num << '\n';
      }
    }
    // [oO][H][nN]
    if ((format[1] == 'H') 
      && (format[2] == 'n' || format[2] == 'N'))
    {
      ofs << std::setw(cwo + cs1) << "oct" << std::setw(cs2)
        << " " << std::setw(cwh) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwo + cs1) << fsu::oct << num << std::setw(cs2)
          << "  " << std::setw(cwh) << fsu::Hex << num << '\n';
      }
    }
    // [oO][oO][nN]
    if (((format[1] == 'o') || (format[1] == 'O'))
      && ((format[2] == 'n') || (format[2] == 'N')))
    {
      ofs << std::setw(cwo + cs1) << "oct" << std::setw(cs2)
        << " " << std::setw(cwo) << "oct" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwo + cs1) << fsu::oct << num << std::setw(cs2)
          << "  " << std::setw(cwo) << fsu::oct << num << '\n';
      }
    }
    // [oO][oO][fF]
    if (((format[1] == 'o') || (format[1] == 'O'))
      && ((format[2] == 'f') || (format[2] == 'F')))
    {
      ofs << std::setw(cwo + cs1) << "oct" << std::setw(cs2)
        << " " << std::setw(cwo) << "oct" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwo + cs1) << fsu::oct << num << std::setw(cs2)
          << "  " << std::setw(cwo) << fsu::octFill << num << '\n';
      }
    }
    // [oO][oO][bB]
    if (((format[1] == 'o') || (format[1] == 'O'))
      && ((format[2] == 'b') || (format[2] == 'B')))
    {
      ofs << std::setw(cwo + cs1) << "oct" << std::setw(cs2)
        << " " << std::setw(cwo + 1) << "oct" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwo + cs1) << fsu::oct << num << std::setw(cs2)
          << "  " << std::setw(cwo + 1) << fsu::octShowBase << num << '\n';
      }
    }
  }
  // **Input HEXADECIMAL** [hH][?][?]
  if (format[0] == 'h' || format[0] == 'H')
  {
    // [hH][dD][ANY]
    if ((format[1] == 'd') || (format[1] == 'D'))
    {
      ofs << std::setw(cwh + cs1) << "hex" << std::setw(cs2)
        << " " << std::setw(cwd) << "dec" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwh + cs1) << fsu::hex << num << std::setw(cs2)
          << "  " << std::setw(cwd) << fsu::dec << num << '\n';
      }
    }
    // [hH][oO][nN]
    if (((format[1] == 'o') || (format[1] == 'O'))
      && ((format[2] == 'n') || (format[2] == 'N')))
    {
      ofs << std::setw(cwh + cs1) << "hex" << std::setw(cs2)
        << " " << std::setw(cwo) << "oct" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwh + cs1) << fsu::hex << num << std::setw(cs2)
          << "  " << std::setw(cwo) << fsu::oct << num << '\n';
      }
    }
    // [hH][oO][fF]
    if (((format[1] == 'o') || (format[1] == 'O'))
      && ((format[2] == 'f') || (format[2] == 'F')))
    {
      ofs << std::setw(cwh + cs1) << "hex" << std::setw(cs2)
        << " " << std::setw(cwo) << "oct" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwh + cs1) << fsu::hex << num << std::setw(cs2)
          << "  " << std::setw(cwo) << fsu::octFill << num << '\n';
      }
    }
    // [hH][oO][bB]
    if (((format[1] == 'o') || (format[1] == 'O'))
      && ((format[2] == 'b') || (format[2] == 'B')))
    {
      ofs << std::setw(cwh + cs1) << "hex" << std::setw(cs2)
        << " " << std::setw(cwo + 1) << "oct" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwh + cs1) << fsu::hex << num << std::setw(cs2)
          << "  " << std::setw(cwo + 1) << fsu::octShowBase << num << '\n';
      }
    }
    // [hH][h][bB]
    if ((format[1] == 'h')
      && ((format[2] == 'b') || (format[2] == 'B')))
    {
      ofs << std::setw(cwh + cs1) << "hex" << std::setw(cs2)
        << " " << std::setw(cwh + 2) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwh + cs1) << fsu::hex << num << std::setw(cs2)
          << "  " << std::setw(cwh + 2) << fsu::hexShowBase << num << '\n';
      }
    }
    // [hH][h][nN]
    if ((format[1] == 'h')
      && ((format[2] == 'n') || (format[2] == 'N')))
    {
      ofs << std::setw(cwh + cs1) << "hex" << std::setw(cs2)
        << " " << std::setw(cwh) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwh + cs1) << fsu::hex << num << std::setw(cs2)
          << "  " << std::setw(cwh) << fsu::hex << num << '\n';
      }
    }
    // [hH][h][fF]
    if ((format[1] == 'h')
      && ((format[2] == 'f') || (format[2] == 'F')))
    {
      ofs << std::setw(cwh + cs1) << "hex" << std::setw(cs2)
        << " " << std::setw(cwh) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwh + cs1) << fsu::hex << num << std::setw(cs2)
          << "  " << std::setw(cwh) << fsu::hexFill << num << '\n';
      }
    }
    // [hH][H][bB]
    if ((format[1] == 'H')
      && ((format[2] == 'b') || (format[2] == 'B')))
    {
      ofs << std::setw(cwh + cs1) << "hex" << std::setw(cs2)
        << " " << std::setw(cwh + 2) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwh + cs1) << fsu::hex << num << std::setw(cs2)
          << "  " << std::setw(cwh + 2) << fsu::HexShowBase << num << '\n';
      }
    }
    // [hH][H][nN]
    if ((format[1] == 'H')
      && ((format[2] == 'n') || (format[2] == 'N')))
    {
      ofs << std::setw(cwh + cs1) << "hex" << std::setw(cs2)
        << " " << std::setw(cwh) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwh + cs1) << fsu::hex << num << std::setw(cs2)
          << "  " << std::setw(cwh) << fsu::Hex << num << '\n';
      }
    }
    // [hH][H][fF]
    if ((format[1] == 'H')
      && ((format[2] == 'f') || (format[2] == 'F')))
    {
      ofs << std::setw(cwh + cs1) << "hex" << std::setw(cs2)
        << " " << std::setw(cwh) << "hex" << '\n';
      while (ifs >> num)
      {
        ofs << std::setw(cwh + cs1) << fsu::hex << num << std::setw(cs2)
          << "  " << std::setw(cwh) << fsu::HexFill << num << '\n';
      }
    }
  }
  ifs.close();
  ofs.close();
}