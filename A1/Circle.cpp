#include <iostream>
#include "Circle.hpp"
#include <cmath>

Circle::Circle(const point_t &pos ,const double circle_radius):
  Shape(pos),
  radius_(circle_radius)
{}

double Circle::getArea() const
{
  return radius_*radius_*M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return {radius_,radius_,pos_};
}

point_t Circle::move(const double x, const double y)
{
  pos_.x = x;
  pos_.y = y;
  return { pos_.x,pos_.y };
}

point_t Circle::move( const point_t &)
{
  return pos_;
}

void Circle::printShapeInfo() const
{
  std::cout
  << "Circle Properties:" << "\n"
  << "Radius: " << radius_ << "\n";
}
