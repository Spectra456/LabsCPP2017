#include <iostream>
#include "Queue.hpp"



int main(int argc, char** argv)
{
  try
  {
    if (argc != 2)
    {
      std::cerr <<"Must be one argument";
      return 1;
    }
    else if(std::string(argv[1]) == "1")
    {
      return part1();
    }
    else if (std::string(argv[1]) == "2")
    {
      return part2();
    }
    else
    {
      std::cerr <<"Invalid argument";
      return 1;
    }
  }

  catch(const std::exception &e)
  {
    std::cerr << e.what();
    return 1;
  }

  return 0;
}

