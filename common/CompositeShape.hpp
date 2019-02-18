#ifndef COMPOSITESHAPE_HPP_INCLUDED
#define COMPOSITESHAPE_HPP_INCLUDED
#include <memory>
#include "Shape.hpp"

class CompositeShape:
  public Shape
{
private:
  std::unique_ptr <std::shared_ptr<Shape>[]> shapes_;
  size_t size_;
public:
  CompositeShape(const std::shared_ptr<Shape> &);
  CompositeShape(const CompositeShape &);
  CompositeShape & operator=(const CompositeShape &);
  bool operator==(const CompositeShape &);
  void addShape(const std::shared_ptr<Shape> &);
  std::string getName() const override;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void printData() const override {};
  void move(double, double) override;
  void move(const point_t &) override;
  void scale(double) override;
  void rotate(double) override;
};

bool operator==(const CompositeShape &, const CompositeShape &);

#endif
