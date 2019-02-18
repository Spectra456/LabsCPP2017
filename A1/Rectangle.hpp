#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "Shape.hpp"
#include "base-types.hpp"

class Rectangle:public Shape
{
protected:
  double width_;
  double height_;
  rectangle_t framerect;
public:
  Rectangle(const point_t &,const double,const double);
  double getArea() const ;
  rectangle_t getFrameRect() const;
  point_t move( const point_t &);
  point_t move(const double,const double);
  void printShapeInfo() const;
};

#endif // RECTANGLE_HPP_
