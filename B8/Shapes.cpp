#include "Shapes.hpp"

#include <sstream>
#include <iostream>
#include <exception>
#include <string>
#include <cstring>


Shape_n::Shape_n (const Point_n & point) :
  center_ (point)
{
}

Point_n Shape_n::getCenter () const
{
  return center_;
}

bool Shape_n::isMoreLeft (const Shape_n & other) const
{
  return this->getCenter ().x < other.getCenter ().x;
}

bool Shape_n::isUpper (const Shape_n & other) const
{
  return this->center_.y > other.getCenter ().y;
}

Circle_n::Circle_n (const Point_n & point) :
  Shape_n (point)
{
}

void Circle_n::draw (std::ostream & ostream) const
{
  ostream << "CIRCLE" << center_ << "\n";
}

Square_n::Square_n (const Point_n & point) :
  Shape_n (point)
{
}

void Square_n::draw (std::ostream & ostream) const
{
  ostream << "SQUARE" << center_ << "\n";
}

Triangle_n::Triangle_n (const Point_n & point) :
  Shape_n (point)
{
}

void Triangle_n::draw (std::ostream & ostream) const
{
  ostream << "TRIANGLE" << center_ << "\n";
}

std::istream & operator>>(std::istream & istream, Shape_n & shape)
{
  std::string str = "";
  Point_n point;
  istream >> str >> point;

  if (strcmp (str.data (), "CIRCLE") == 0) {
    shape = Circle_n (point);
    return istream;
  }
  if (strcmp (str.data (), "TRIANGLE") == 0) {
    shape = Triangle_n (point);
    return istream;
  }
  if (strcmp (str.data (), "SQUARE") == 0) {
    shape = Square_n (point);
    return istream;
  }

  throw std::invalid_argument ("Invalid Data");
}

std::ostream & operator<<(std::ostream & ostream, const Shape_n & shape)
{
  shape.draw (ostream);
  return ostream;
}

std::istream & operator>>(std::istream & istream, ShapeKeeper & shape)
{
  std::string str = "";
  Point_n point;

  std::getline (istream, str, '(');
  istream >> point;

  if ((str.empty ()) || ((strcmp(str.data(), "\n") == 0)) || (str[0] == '\t')) {
    istream.setstate (std::ios_base::failbit);
    return istream;
  }

  if (istream.eof ()) {
    throw std::invalid_argument ("Invalid Data");
  }

  if (str.find("CIRCLE") != std::string::npos) {
    shape.shape_ = std::shared_ptr<Shape_n> (new Circle_n (point));
    return istream;
  }
  if (str.find("TRIANGLE") != std::string::npos) {
    shape.shape_ = std::shared_ptr<Shape_n> (new Triangle_n (point));
    return istream;
  }
  if (str.find("SQUARE") != std::string::npos) {
    shape.shape_ = std::shared_ptr<Shape_n> (new Square_n (point));
    return istream;
  }

  throw std::invalid_argument ("Invalid Data");
}

std::ostream & operator<<(std::ostream & ostream, const ShapeKeeper & shape)
{
  ostream << *(shape.shape_);
  return ostream;
}

std::istream & operator>>(std::istream & istream, Point_n & point)
{
  std::string str = "";
  char symbol = 0;

  std::getline (istream, str, ')');
  if (str.empty ()) {
    return istream;
  }

  if ((str.find ('\n') != std::string::npos) || (istream.eof())) {
    throw std::invalid_argument ("Invalid Data");
  }

  std::stringstream stream (str);

  stream >> point.x >> symbol >> point.y;
  if (symbol != ';') {
    throw std::invalid_argument ("Invalid Data");
  }

  return istream;
}

std::ostream & operator<<(std::ostream & ostream, const Point_n & point)
{
  ostream << " (" << point.x << "; " << point.y << ")";
  return ostream;
}

ShapeKeeper::ShapeKeeper () :
  shape_ (nullptr)
{
}

