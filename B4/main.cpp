#include <iostream>
#include <exception>
#include "missionfactorial.hpp"
#include "missionnotebook.hpp"

int main(int agrc, char *argv[])
{
  if (agrc != 2)
  {
    std::cerr << "incorrect parameters" << std::endl;
    return 1;
  }
  try
  {
    switch (std::atoi(argv[1]))
    {
    case 1:
      bookInterface();
      break;
    case 2:
      conclusionFactorial();
      break;
    default:
      throw std::invalid_argument("Invalid item number.");
    }
  }
  catch (std::ios_base::failure & exception)
  {
    std::cerr << exception.what() << std::endl;
    return 1;
  }
  catch (std::invalid_argument & exception)
  {
    std::cerr << exception.what() << std::endl;
    return 1;
  }

  return 0;
}
