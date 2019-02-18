#ifndef DETAIL_HPP
#define DETAIL_HPP

#include "DataStructure.hpp"

std::istream& operator>>(std::istream& is, DataStructure& ds);
std::ostream& operator<<(std::ostream& os,const DataStructure& one);

#endif // DETAIL_HPP
