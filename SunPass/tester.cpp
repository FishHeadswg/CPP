/*
   tester.cpp

   Chris Lacher
   10-10-13

   Test harness for the vehicle object hierarchy

   VehicleType is an enumerated type with values:

     badSn, vehicle, car, truck, van, tanker, flatbed

   These classes are tested:

     Vehicle;
     Car;
     Truck;
     Van;
     Tanker;
     Flatbed;
     Box;
     Cylinder;
     Plane;
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <vehicles.h>

#pragma warning(disable: 4996)

char  snMessage  [54] = "*** OOPS - serial number not owned by vehicle object";
char  dotMessage [55] = "*** OOPS - license number not owned by vehicle object";
char  dotLicense [15] = "DOTLICENSE OK";
// const size_t maxEntrySize(1 + strlen(dotMessage));
const size_t maxEntrySize = 55;

int main()
{
  Vehicle *   Vptr;              // pointer to dynamically allocated Vehicle object
  VehicleType v;                 // to hold type of vehicle
  char        sn [maxEntrySize]; // to hold user entry
  char        dot[maxEntrySize]; // used to test ownership of DOT License number
  std::cout << std::fixed << std::showpoint << std:: setprecision(2); // set float output format

  do
  {
    std::cout << "\nEnter sn ('x' to quit): ";
    std::cin >> std::setw(maxEntrySize) >> sn;
    if (sn[0] == 'x') break;
    v = Vehicle::SnDecode(sn);
    switch (v)
    {
      case vehicle:
        Vptr = new Vehicle(sn, 1);
        break;
      case car:
        Vptr = new Car(sn, 2);
        break;
      case truck:
        strcpy (dot,dotLicense);
        Vptr = new Truck(sn, 3, dot);
        break;
      case van:
        strcpy (dot,dotLicense);
        Vptr = new Van(sn, 4, dot, 20, 4, 8);
        break;
      case tanker:
        strcpy (dot,dotLicense);
        Vptr = new Tanker(sn, 5, dot, 40, 3);
        break;
      case flatbed:
        strcpy (dot,dotLicense);
        Vptr = new Flatbed(sn, 6, dot, 20, 6);
        break;
      case badSn:
        Vptr = new Vehicle ("BadSerialNumber",0);
        break;
      default:  // should never get here
        std::cerr << "** ERROR: bad serial number passed to decision logic\n";
        break;
    } // end switch

    strcpy (sn, snMessage);
    strcpy (dot, dotMessage);
    std::cout << "Short Name:    " << Vptr -> ShortName() << '\n';
    std::cout << "Toll Charge:   " << Vptr -> Toll() << '\n';
    std::cout << "Serial Number: " << Vptr -> SerialNumber() << '\n';
    std::cout << "Passenger Cap: " << Vptr -> PassengerCapacity() << '\n';
    std::cout << "Load Capacity: " << Vptr -> LoadCapacity() << '\n';
    if ( truck <= v ) // all types of trucks
    { 
      std::cout << "DOT License:   " << (dynamic_cast<Truck*>(Vptr)) -> DOTLicense() << '\n';
    }

    delete Vptr;
  } // end do
  while (sn[0] != '0');

  return 0;
} // end main
