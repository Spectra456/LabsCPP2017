#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include "base-types.hpp"

class Shape
{
public:
  point_t pos_;
	Shape(const point_t &);
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual point_t move(const point_t &) = 0;
  virtual point_t move(const double , const double) = 0;
  virtual void printShapeInfo() const = 0;
  void printInfo() const;
};

#endif // SHAPE_HPP
