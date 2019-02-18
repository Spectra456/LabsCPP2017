#include <iostream>
#include "Rectangle.hpp"
#include "Circle.hpp"

int main()
{
  Rectangle rectangle({0, 0}, 20, 10);
  Shape *shape_1 = &rectangle;
  std::cout << "Rectangle was created"<<"\n";
  shape_1 -> printShapeInfo();
  double dx = 10;
  double dy = 20;
  shape_1 -> move(dx, dy);
  std::cout <<"Rectangle was moved to (" << dx << ", " << dy << ")"<< "\n" ;
  shape_1 -> printShapeInfo();
  std::cout << "===========================" << "\n";
  Circle circle({10, 10}, 10);
  Shape *shape_2 = &circle;
  std::cout << "Circle was created" <<"\n";
  shape_2 -> printShapeInfo();
  point_t pos = {0, 0};
  shape_2 -> move(pos);
  std::cout << "Circle was moved to (" << pos.x << ", " << pos.y << ")" << "\n";
  shape_2 -> printShapeInfo();

  return 0;
}
