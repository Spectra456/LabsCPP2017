#include "missionfactorial.hpp"
#include <algorithm>
#include <iostream>

void conclusionFactorial()
{
  Container container;

  std::copy(container.begin(), container.end(), std::ostream_iterator<size_t>(std::cout, " "));
  std::cout << std::endl;

  std::reverse_copy(container.begin(), container.end(), std::ostream_iterator<size_t>(std::cout, " "));
  std::cout << std::endl;
}
