#ifndef BASE_TYPES_HPP_
#define BASE_TYPES_HPP_

struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  point_t pos;
  double width;
  double height;
};

bool isClose(double, double);

#endif // BASE_TYPES_HPP_
