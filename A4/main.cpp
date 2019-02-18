#include <iostream>
#include <cmath>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "CompositeShape.hpp"
#include "MatrixShape.hpp"

int main()
{
  auto rectangle_1 = std::make_shared<Rectangle>(point_t{-1, -2.5}, 6, 3);
  std::cout << "\n" << "Rectangle_1 was created << \n\n";
  rectangle_1 -> printData();
  auto circle = std::make_shared<Circle>(point_t{3, 0}, 3);
  std::cout << "\n" << "Circle was created" << "\n\n";
  circle -> printData();

  auto rectangle_2 = std::make_shared<Rectangle>(point_t{-2.5, 1}, 3, 2);
  std::cout << "Rectangle_2 was created" << "\n\n";
  rectangle_2 -> printData();

  MatrixShape matrix_shape(rectangle_1);
  std::cout << "\n" << " Matrix was created" << "\n\n";
  matrix_shape.addShape(circle);
  matrix_shape.addShape(rectangle_2);
  matrix_shape.print();
}

