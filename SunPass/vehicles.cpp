/*
vehicles.cpp
10-24-13
Trevor Richardson

Implements Vehicle, Car, Truck, Van, Tanker, and Flatbed classes.

*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vehicles.h>
#include <shapes.h>

VehicleType Vehicle::SnDecode(const char *sn)
{
  //std::cout << "sn    = " << sn << "\n";
  //std::cout << "sn[0] = " << sn[0] << "\n";
  switch (sn[0])
  {
  case '1':
    return vehicle;
  case '2':
    return car;
  case '3':
    return truck;
  case '4':
    return van;
  case '5':
    return tanker;
  case '6':
    return flatbed;
  default:
    return badSn;
  }
}

Vehicle::Vehicle()
: serialNumber_(0), passengerCapacity_(0)
{}

Vehicle::Vehicle( const char *serialNumber, unsigned int passengerCapacity )
: serialNumber_(0), passengerCapacity_(passengerCapacity)
{
  //std::cout << "Vehicle()\n";
  serialNumber_ = new(std::nothrow) char[1 + strlen(serialNumber)];
  if (serialNumber_ == 0)
  {
    std::cerr << "Unable to allocate memory for Vehicle::serialNumber\n";
    exit(EXIT_FAILURE);
  }
  strcpy(serialNumber_, serialNumber);
}

Vehicle::~Vehicle()
{
  //std::cout << "~Vehicle()\n";
  delete[] serialNumber_;
}

const char *Vehicle::SerialNumber() const
{
  return serialNumber_;
}

float Vehicle::LoadCapacity() const
{
  return 0.0;
}

unsigned int Vehicle::PassengerCapacity() const
{
  return passengerCapacity_;
}

const char *Vehicle::ShortName() const
{
  return "UNK";
}

float Vehicle::Toll() const
{
  return 2.00; // Non-Truck toll
}

Car::Car()
: Vehicle()
{}

Car::Car( const char *serialNumber, unsigned int passengerCapacity )
: Vehicle( serialNumber, passengerCapacity)
{
  //std::cout << "Car()\n";
}

Car::~Car()
{
  //std::cout << "~Car()\n";
}

const char *Car::ShortName() const
{
  return "CAR";
}

Truck::Truck()
: Vehicle(), DOTLicense_(0)
{}

Truck::Truck( const char *serialNumber, unsigned int passengerCapacity, 
  char *DOTLicense)
  : Vehicle(serialNumber, passengerCapacity), DOTLicense_(0)
{
  //std::cout << "Truck()\n";
  DOTLicense_ = new(std::nothrow) char[1 + strlen(DOTLicense)];
  if (DOTLicense_ == 0)
  {
    std::cerr << "Unable to allocate memory for Truck::DOTLicense\n";
    exit(EXIT_FAILURE);
  }
  strcpy(DOTLicense_, DOTLicense);
}

Truck::~Truck()
{
  //std::cout << "~Truck()\n";
  delete[] DOTLicense_;
}

float Truck::LoadCapacity() const
{
  return Vehicle::LoadCapacity();
}

const char *Truck::ShortName() const
{
  return "TRK";
}

float Truck::Toll() const
{
  return 10.00; // Truck toll
}

const char *Truck::DOTLicense() const
{
  return DOTLicense_;
}

Van::Van()
: Truck(), Box()
{}

Van::Van( const char *serialNumber, unsigned int passengerCapacity,
  char *DOTLicense, float length, float width, float height)
  : Truck(serialNumber, passengerCapacity, DOTLicense),
  Box(length, width, height) // Truck and Box constructor initializations
{
  //std::cout << "Van()\n";
}

Van::~Van()
{
  //std::cout << "~Van()\n";
}

float Van::LoadCapacity() const
{
  return Box::Volume();
}

const char *Van::ShortName() const
{
  return "VAN";
}

Tanker::Tanker()
: Truck(), Cylinder()
{}

Tanker::Tanker( const char *serialNumber, unsigned int passengerCapacity,
  char *DOTLicense, float length, float radius )
  : Truck(serialNumber, passengerCapacity, DOTLicense),
  Cylinder(length, radius) // Truck and Cylinder constructor initializations
{
  //std::cout << "Tanker()\n";
}

Tanker::~Tanker()
{
  //std::cout << "~Tanker()\n";
}

float Tanker::LoadCapacity() const
{
  return Cylinder::Volume();
}

const char *Tanker::ShortName() const
{
  return "TNK";
}

Flatbed::Flatbed()
: Truck(), Plane()
{}

Flatbed::Flatbed( const char *serialNumber, unsigned int passengerCapacity,
  char *DOTLicense, float length, float width)
  : Truck(serialNumber, passengerCapacity, DOTLicense),
  Plane(length, width) // Truck and Plane constructor initializations
{
  //std::cout << "Flatbed()\n";
}

Flatbed::~Flatbed()
{
  //std::cout << "~Flatbed()\n";
}

float Flatbed::LoadCapacity() const
{
  return Plane::Area();
}

const char *Flatbed::ShortName() const
{
  return "FLT";
}