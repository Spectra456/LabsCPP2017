#include <iostream>
#include "Shape.hpp"
void Shape::printShapeInfo() const
{
  printData();
  rectangle_t frame_rect = getFrameRect();
  std::cout
    << "area: " << getArea() << "\n"
    << "Frame Rectangle Properities" << "\n"
    << "Position:" << "\n"
    << "x: " << frame_rect.pos.x << "\n"
    << "y: " << frame_rect.pos.y << "\n"
    << "width: " << frame_rect.width << "\n"
    << "height: " << frame_rect.height << "\n"
    << "=============================== " << "\n";
}
