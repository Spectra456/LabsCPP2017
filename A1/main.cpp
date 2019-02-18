#include "Rectangle.hpp"
#include "Circle.hpp"
#include "base-types.hpp"
#include "iostream"

int main()
{
  Rectangle r({ 0,0 },10, 14);
  Shape * rectangle=&r;
  rectangle->getArea();
  rectangle->getFrameRect();
  rectangle->printInfo();
  rectangle->move(5, 4);
  std::cout << "After movement:" << "\n";
  rectangle->getArea();
  rectangle->getFrameRect();
  rectangle->printInfo();
  
  Circle q({ 0,0 },10);
  Shape * circle=&q;
  circle->getArea();
  circle->getFrameRect();
  circle->printInfo();
  circle->move(7, 4);
  std::cout << "After movement" << "\n";
  circle->getArea();
  circle->getFrameRect();
  circle->printInfo();
  return 0;
}


