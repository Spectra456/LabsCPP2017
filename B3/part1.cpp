#include <iostream>
#include <string>
#include <sstream>
#include "Queue.hpp"

int part1()
{
  detail::Queue<std::string> Array;

  std::string line;
  while(std::getline(std::cin, line))
  {
    std::stringstream stream(line);
    std::string instruction;
    stream >> instruction;

    if(instruction == "add")
    {
      std::string priority;
      stream >> priority;

      std::string data;
      stream.ignore();
      std::getline(stream, data);

      if(data.empty())
      {
        std::cout << "<INVALID COMMAND>" << std::endl;
      }
      else if(priority == "high")
      {
        Array.putElement(data, ElementPriority::high);
      }
      else if(priority == "normal")
      {
        Array.putElement(data, ElementPriority::normal);
      }
      else if(priority == "low")
      {
        Array.putElement(data, ElementPriority::low);
      }
      else
      {
        std::cout << "<INVALID COMMAND>" << std::endl;
      }
    }
    else if(instruction == "accelerate" && stream.eof())
    {
      Array.Accelerate();
    }
    else if(instruction == "get" && stream.eof())
    {
      if(Array.empty())
      {
        std::cout << "<EMPTY>" << std::endl;
      }
      else
      {
        std::cout << Array.getElement() << std::endl;
      }
    }
    else
    {
      std::cout << "<INVALID COMMAND>" << std::endl;
    }

    if(std::cin.eof())
    {
      break;
    }
  }

  return 0;
}


