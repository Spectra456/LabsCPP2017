#include <iostream>
#include "Rectangle.hpp"

Rectangle::Rectangle(const point_t &pos, const double rectangle_width,const double rectangle_height):
  Shape(pos),
  width_(rectangle_width),
  height_(rectangle_height)
  {}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t  Rectangle::getFrameRect() const
{
  return {width_,height_,pos_};
}

point_t Rectangle::move( const double  dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
  return{ pos_.x,pos_.y };
}

point_t Rectangle::move(const point_t &)
{
  return pos_;
}

void Rectangle::printShapeInfo() const
{
  std::cout
  << "Rectangle Properties:" << "\n"
  << "Height: " << height_ << "\n"
  << "Width: " << width_ << "\n";
}
