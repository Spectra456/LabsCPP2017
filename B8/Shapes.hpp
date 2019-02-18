#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <iostream>
#include <memory>

struct Point_n
{
  int x, y;
};

class Shape_n
{
public:
  Shape_n () = default;
  Shape_n (const Point_n & point);
  virtual ~Shape_n () = default;

  Point_n getCenter () const;
  bool isMoreLeft (const Shape_n & other) const;
  bool isUpper (const Shape_n & other) const;
  virtual void draw (std::ostream & ostream) const = 0;

protected:
  Point_n center_;
};

class Circle_n : public Shape_n
{
public:
  Circle_n (const Point_n & point);

  void draw (std::ostream & ostream) const override;
};

class Triangle_n : public Shape_n
{
public:
  Triangle_n (const Point_n & point);

  void draw (std::ostream & ostream) const override;
};

class Square_n : public Shape_n
{
public:
  Square_n (const Point_n & point);

  void draw (std::ostream & ostream) const override;
};

class ShapeKeeper
{
public:
  ShapeKeeper ();
 // Shape_nKeeper (Shape_n * shape);
  ShapeKeeper (const ShapeKeeper & other) = default;

  std::shared_ptr<Shape_n> shape_;
};

std::istream & operator>>(std::istream &, Shape_n & shape);
std::ostream & operator<<(std::ostream &, const Shape_n & shape);
std::istream & operator>>(std::istream &, ShapeKeeper & shape);
std::ostream & operator<<(std::ostream &, const ShapeKeeper & shape);
std::istream & operator>>(std::istream &, Point_n & point);
std::ostream & operator<<(std::ostream &, const Point_n & point);

#endif // SHAPES_HPP

