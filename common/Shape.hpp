#ifndef SHAPE_HPP_
#define SHAPE_HPP_
#include <string>
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  void printShapeInfo() const;
  virtual std::string getName() const = 0;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(double, double) = 0;
  virtual void move(const point_t &) = 0;
  virtual void scale(double) = 0;
  virtual void rotate(double) = 0;
private:
  virtual void printData() const = 0;
};

#endif // SHAPE_HPP_
