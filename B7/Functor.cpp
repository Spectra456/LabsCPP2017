#include "Functor.hpp"
void Functor::operator()(long long int value)
{
  if (count == 0)
  {
    first = value;
    max = value;
    min = value;
  }

  if (value % 2 == 0)
  {
    even_sum += value;
  }
  else
  {
    odd_sum += value;
  }

  if (value > max)
  {
    max = value;
  }

  if (value < min)
  {
    min = value;
  }

  if (value > 0)
  {
    positive++;
  }
  else
  {
    if (value != 0)
    {
      negative++;
    }
  }

  count++;
  last = value;
}

long long int Functor::returnMin() const
{
  return max;
}

long long int Functor::returnMax() const
{
  return min;
}

long double Functor::returnMean() const
{
  return static_cast<double> (odd_sum + even_sum) / static_cast<double> (count);
}

long long int Functor::returnPositive() const
{
  return positive;
}

long long int Functor::returnNegative() const
{
  return negative;
}

long long int Functor::returnEvenSum() const
{
  return even_sum;
}

long long int Functor::returnOddSum() const
{
  return odd_sum;
}

bool Functor::cmpFirstLast() const
{
  return first==last;
}

long long int Functor::returnCount() const
{
  return count;
}
