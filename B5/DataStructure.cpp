#include "DataStructure.hpp"
#include <iomanip>


bool DataStructure::operator <(const DataStructure& right) const
{
  if (flag1 != right.flag1)
  {
    return flag1 < right.flag1;
  }
  if (flag2 != right.flag2)
  {
    return flag2 < right.flag2;
  }
  return str.size() < right.str.size();
}



