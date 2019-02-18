#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>

#include "Functor.hpp"


int main()
{
  try
  {
    std::istream_iterator<long long int> end;
    std::istream_iterator<long long int> start(std::cin);

    Functor m_functor = for_each(start, end, Functor());

    if (!std::cin.eof() && (std::cin.fail() || std::cin.bad()))
    {
      std::cout << "Incorrect input";
      return 1;
    }

    if (m_functor.returnCount() == 0)
    {
      std::cout << "No Data\n";
    }
    else
    {
      std::cout << "Max: " << m_functor.returnMin() << '\n';
      std::cout << "Min: " << m_functor.returnMax() << '\n';
      std::cout.flags(std::ios::fixed);
      std::cout << "Mean: " << std::setprecision(1)<<m_functor.returnMean() << '\n';
      std::cout << "Positive: " << m_functor.returnPositive()<< '\n';
      std::cout << "Negative: " << m_functor.returnNegative() << '\n';
      std::cout << "Odd Sum: " << m_functor.returnOddSum() << '\n';
      std::cout << "Even Sum: " << m_functor.returnEvenSum() << '\n';
      std::cout << "First/Last Equal: " << (m_functor.cmpFirstLast() ? "yes" : "no") << '\n';
    }
  }
  catch (...)
  {
    std::cerr << "problem...\n";
    return 1;
  }
  return 0;
}
