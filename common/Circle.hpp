#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_
#include "Shape.hpp"

class Circle:
  public Shape
{
private:
  point_t pos_;
  double radius_;
public:
  Circle(const point_t &pos, double radius);
  bool operator==(const Circle &);
  double getRadius() const;
  std::string getName() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void printData() const override;
  void move(double, double) override;
  void move(const point_t &) override;
  void scale(double ) override;
  void rotate(double) override {}
};

#endif // CIRCLE_HPP_
