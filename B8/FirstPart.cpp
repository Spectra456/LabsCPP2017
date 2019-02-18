#include "Parts.hpp"

#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>

void doFirstPart (std::istream & istream, std::ostream & ostream)
{
  if (istream && ostream) {
    std::transform ((std::istream_iterator<double> (istream)), std::istream_iterator<double> (), std::ostream_iterator<double> (ostream, " "), [](double n) {
      return n * M_PI;
    });
    if (!istream.eof ()) {
      throw std::invalid_argument ("Invalid Data");
    }
  } else {
    throw std::ios_base::failure ("Stream Crash");
  }
}
