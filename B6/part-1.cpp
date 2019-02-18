#include "task-headers.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <iterator>

int part_1()
{
  std::unordered_set<std::string> UniqueWords(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>());

 /* std::for_each(UniqueWords.begin(), UniqueWords.end(), [](const std::string& str)
                                                          {
                                                            std::cout << str << std::endl;
                                                          });*/
  std::copy(UniqueWords.begin(), UniqueWords.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
  return 0;
}
