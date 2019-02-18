#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_
#include "Shape.hpp"

class Rectangle:
  public Shape
{
private:
  point_t corners_[4];
  double width_;
  double height_;
public:
  Rectangle(const point_t &pos, double width, double height);
  bool operator==(const Rectangle &);
  double getWidth() const;
  double getHeight() const;
  std::string getName() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void printData() const override;
  void move(double, double) override;
  void move(const point_t &) override;
  void scale(double) override;
  void rotate(double) override;
};

bool operator==(const Rectangle &, const Rectangle &);

#endif // RECTANGLE_HPP_
