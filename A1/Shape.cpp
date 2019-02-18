#include <iostream>
#include "Shape.hpp"

Shape::Shape(const point_t & pos) :
  pos_(pos)
{}

void Shape::printInfo() const
{
  this->printShapeInfo();
  std::cout
  << "Position: " << "\n"
  << "x: " << pos_.x << "\n"
  << "y: " << pos_.y << "\n"
  << "Area: " << getArea() << "\n"
  << "Frame Rectangle Properties:" << "\n";
  rectangle_t fRect=this -> getFrameRect();
  std::cout
  << "Height: " << fRect.height << "\n"
  << "Width: " << fRect.width << "\n"
  << "Postion: " << "\n"
  << "x: " << fRect.pos.x << "\n"
  << "y: " << fRect.pos.y << "\n"
  << "===========================" << "\n";
}
