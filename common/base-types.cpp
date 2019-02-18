#include <cmath>
#include "base-types.hpp"

bool isClose(double d1, double d2)
{
  return (fabs(d1 - d2) <= 0.0001);
}
