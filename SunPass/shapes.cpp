/*
shapes.cpp
10-24-13
Trevor Richardson

Implements Box, Cylinder, and Plane classes.

*/

#include <iostream>
#include <shapes.h>

const double PI = 3.14159;

Box::Box()
: length_(0), width_(0), height_(0)
{}

Box::Box(float length, float width, float height)
: length_(length), width_(width), height_(height)
{
  // std::cout << "Box()\n";
}

Box::~Box()
{
 // std::cout << "~Box()\n";
}

float Box::Volume() const
{
  return length_ * width_ * height_;
}

Cylinder::Cylinder()
: length_(0), radius_(0)
{}

Cylinder::Cylinder(float length, float radius)
: length_(length), radius_(radius)
{
//  std::cout << "Cylinder()\n";
}

Cylinder::~Cylinder()
{
//  std::cout << "~Cylinder()\n";
}

float Cylinder::Volume() const
{
  return PI * radius_ * radius_ * length_; // v = pi * r^2 * h
}

Plane::Plane()
: length_(0), width_(0)
{}

Plane::Plane(float length, float width)
: length_(length), width_(width)
{
//  std::cout << "Plane()\n";
}

Plane::~Plane()
{
//  std::cout << "~Plane()\n";
}

float Plane::Area() const
{
  return length_ * width_;
}