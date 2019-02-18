#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Circle.hpp"

Circle::Circle(const point_t &pos, double radius):
  pos_(pos),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("invalid_radius");
  }
}

bool Circle::operator==(const Circle &circle_1)
{
  if (isClose(circle_1.pos_.x, pos_.x) &&
        isClose(circle_1.pos_.y, pos_.y) &&
         isClose(circle_1.radius_, radius_))
  {
    return true;
  }
  else
  {
    return false;
  }
}

double Circle::getRadius() const
{
  return radius_;
}

std::string Circle::getName() const
{
  return "circle";
}

double Circle::getArea() const
{
  return radius_ * radius_ * M_PI ;
}

rectangle_t Circle::getFrameRect() const
{
  return {pos_,2*radius_,2*radius_};
}

void Circle::printData() const
{
  std::cout
    << "Circle Properities:" << "\n"
    << "x: " << pos_.x << "\n"
    << "y: " << pos_.y << "\n"
    << "radius: " << radius_ << "\n";
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::move(const point_t &pos)
{
  pos_ = pos;
}

void Circle::scale(double x)
{
  if (x <= 0)
  {
    throw std::invalid_argument("invalid_scale");
  }

  radius_ *= x;
}
