#include "Queue.hpp"
#include <iostream>
#include <list>

int part2()
{
  std::list<int> list_number;

  size_t Num = 0;
  while(std::cin >> Num)
  {
    if((Num < 1) || (Num > 20))
    {
      throw std::out_of_range("There is illegal number in input");
    }
    list_number.push_back(Num);
  }

   if(std::cin.fail() && !std::cin.eof())
   {
     throw std::invalid_argument("Invalid input");
   }

  if(list_number.size() > 20)
  {
    throw std::invalid_argument("Too many numbers");
  }

  auto i = list_number.begin();
  auto j = std::prev(list_number.end());

  if(list_number.size() == 1)
  {
    std::cout << *i << std::endl;
  }
  else
  {
    while(i != j)
    {
      std::cout << *i << " " << *j << " ";
      i++;
      if(i == j)
      {
        break;
      }
      j--;
    }
    if(list_number.size() % 2 == 1)
    {
      std::cout << *i;
    }
    std::cout << std::endl;
  }

  return 0;
}

