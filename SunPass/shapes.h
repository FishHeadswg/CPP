/*
shapes.h
10-24-13
Trevor Richardson

Defines Box, Cylinder, and Plane classes.

*/

#ifndef SHAPES_H
#define SHAPES_H

class Box
{
public:
  Box(); // default constr
  Box(float, float, float); // 3-arg constructor
  ~Box();
  float Volume() const; // returns volume of box object 
private:
  float length_;
  float width_;
  float height_;
};

class Cylinder
{
public:
  Cylinder(); //default constr
  Cylinder(float, float); // 2-arg constructor
  ~Cylinder();
  float Volume() const; // returns volume of cylinder object  
private:
  float length_;
  float radius_;
};

class Plane
{
public:
  Plane(); // default constr
  Plane(float, float); // 2-arg constructor
  ~Plane();
  float Area() const; // returns area of plane object
private:
  float length_;
  float width_;
};

#endif