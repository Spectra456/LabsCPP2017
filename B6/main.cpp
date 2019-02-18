#include <iostream>
#include "task-headers.hpp"

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    std::cerr <<"Restart and type the arguments, please" <<std::endl;
    return 1;
  }

  char * error;
  int numsize = strtol(argv[1], &error, 10);

  if (*error)
  {
    std::cerr <<"Restart and type correct arguments, please" <<std::endl;
    return 1;
  }

  switch (numsize)
  {
  case 1:
    return part_1();
  case 2:
    /*if (argc <= 2)
    {
      std::cerr <<"Restart and define name of file, please" <<std::endl;
      return 1;
    }*/
    return part_2();
  default:
    std::cerr <<"Restart and type correct arguments, please" <<std::endl;
    return 1;
  }
}
