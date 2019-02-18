#include "detail.hpp"
#include <iomanip>


std::istream& operator >>(std::istream& is, DataStructure& ds)
{
  ds.correct=true;
  is >> ds.flag1;
  if(!is.bad() && !is.fail() && abs(ds.flag1) <= max)
  {
    char sep = '\0';
    is >> sep;
    if (sep != ',')
    {
      ds.correct = false;
      return is;
    }
    is >> ds.flag2;
    if (!is.fail() && !is.bad() && abs(ds.flag2) <= max)
    {
      is >> sep;
      if (sep != ',')
      {
        ds.correct = false;
        return is;
      }
      is >> ds.str;
      char t;
      while (!is.eof())
      {
        is.get(t);
        if (!is.eof())
        {
          ds.str = ds.str + t;
        }
      }
      if (ds.str == "")
      {
        ds.correct = false;
        return is;
      }
    }
    else
    {
      ds.correct=false;
      return is;
    }
  }
  else
  {
    ds.correct=false;
    return is;
  }
  return is;
}

std::ostream& operator<<(std::ostream& os,const DataStructure& one)
{
  os << std::left << std::setw(1) << one.flag1 << std::setw(2) << "," << std::setw(1) << one.flag2
     << std::setw(2) << "," << one.str;
  return os;
}
