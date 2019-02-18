#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "Shape.hpp"
#include "base-types.hpp"

class Circle :public Shape
{
protected:
  double radius_;
  rectangle_t framerect;
  
public:
  Circle(const point_t &,const double);
  double getArea() const;
  rectangle_t getFrameRect() const;
  point_t move(const point_t &);
  point_t move(const double, const double);
  void printShapeInfo() const;
};

#endif // CIRCLE_HPP_
