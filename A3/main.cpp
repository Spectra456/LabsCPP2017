#include <iostream>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "CompositeShape.hpp"

int main()
{
  auto rectangle = std::make_shared<Rectangle>(point_t{0, 0}, 20, 10);
  std::cout << "Rectangle was created" << "\n";
  rectangle -> printShapeInfo();

  auto circle = std::make_shared<Circle>(point_t{10, 10}, 10);
  std::cout << "Circle was created" << "\n";
  circle -> printShapeInfo();

  CompositeShape composite_shape(rectangle);
  std::cout
    <<"\n" << "Composite shape was created" <<"\n"
    << "Rectangle was added to composite shape" <<"\n";
  composite_shape.addShape(circle);
  std::cout << "Circle was added to composite shape" <<"\n";
  composite_shape.printShapeInfo();

  return 0;
}
