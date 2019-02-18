#ifndef DATASTRUCTURE_HPP
#define DATASTRUCTURE_HPP

#include <iostream>
#include <string>

const int max = 5;

struct DataStructure
{
public:
  int flag1;
  int flag2;
  std::string str;
  bool correct;
  bool operator <(const DataStructure& right) const;
};

#endif //DATASTRUCTURE_HPP
