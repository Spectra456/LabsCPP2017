#include <iterator>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "detail.hpp"


int main()
{
  std::vector<DataStructure> vec;
  std::string m_data;
  DataStructure m_new;
  while(!std::cin.eof())
  {
    std::getline(std::cin,m_data);
    if(!std::cin.eof() && m_data!="")
    {
      std::stringstream read(m_data);
      read >> m_new;
      if(!m_new.correct)
      {
        std::cerr<<"Incorrect input";
        return 1;
      }
      vec.push_back(m_new);
    }
  }
  std::sort(vec.begin(),vec.end());
  std::copy(vec.begin(),vec.end(),std::ostream_iterator<DataStructure>(std::cout,"\n"));
  return 0;
}
