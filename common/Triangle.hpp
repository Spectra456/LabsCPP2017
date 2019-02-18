#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_
#include "Shape.hpp"

class Triangle:
  public Shape
{
private:
  point_t corners_[3];
public:
  Triangle(const point_t &, const point_t &, const point_t &);
  bool operator==(const Triangle &);
  point_t getCenter() const;
  std::string getName() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void printData() const override;
  void move(double, double) override;
  void move(const point_t &) override;
  void scale(double) override;
  void rotate(double) override;
};

#endif // TRIANGLE_HPP_
