/*
vehicles.h
10-24-13
Trevor Richardson

Defines Vehicle, Car, Truck, Van, Tanker, and Flatbed classes.

*/

#ifndef VEHICLES_H
#define VEHICLES_H

#include <shapes.h>

enum VehicleType { badSn, vehicle, car, truck, van, tanker, flatbed };

class Vehicle
{
public:
  Vehicle(); // default constructor
  Vehicle( const char *, unsigned int ); // 2-arg constructor
  virtual ~Vehicle();
  const char*           SerialNumber() const; // returns serial number 
  unsigned int          PassengerCapacity() const; //returns passenger capacity
  virtual float         LoadCapacity() const; // returns 0
  virtual const char*   ShortName() const; // returns "UNK"
  virtual float         Toll() const; // returns toll using fee schedule
  static  VehicleType   SnDecode(const char* sn);
private:
  char *        serialNumber_;
  unsigned int passengerCapacity_;
};

class Car : public Vehicle
{
public:
  Car();
  Car( const char *, unsigned int );
  virtual ~Car();
  const char* ShortName() const; // returns "CAR" 
};

class Truck : public Vehicle
{
public:
  Truck();
  Truck( const char *, unsigned int, char * );
  virtual ~Truck();
  const char*   ShortName() const;  // returns "TRK"
  float         Toll() const;  // returns toll using fee schedule
  const char*   DOTLicense() const;  // returns the license no  
  virtual float LoadCapacity() const; 
private:
  char *DOTLicense_;
};

class Van : public Truck, public Box
{
public:
  Van();
  Van( const char *, unsigned int, char *, float, float, float );
  virtual ~Van();
  float         LoadCapacity() const;  // returns volume of box  
  const char*   ShortName() const;  // returns "VAN"
};

class Tanker : public Truck, public Cylinder
{
public:
  Tanker();
  Tanker( const char *, unsigned int, char *, float, float );
  virtual ~Tanker();
  float LoadCapacity() const;  // returns volume of cylinder  
  const char*   ShortName() const;  // returns "TNK"
};

class Flatbed : public Truck, public Plane
{
public:
  Flatbed();
  Flatbed( const char *, unsigned int, char *, float, float );
  virtual ~Flatbed();
  float         LoadCapacity() const;  // returns area of plane  
  const char*   ShortName() const;  // returns "FLT"  
};

#endif