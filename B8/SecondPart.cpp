#include "Parts.hpp"

#include <iterator>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <memory>

#include "Shapes.hpp"

void doSecondPart (std::istream & istream, std::ostream & ostream)
{
  std::vector<ShapeKeeper> shapes ((std::istream_iterator<ShapeKeeper> (istream)), std::istream_iterator<ShapeKeeper> ());

  std::cout << "Original:\n";
  std::copy (shapes.begin (), shapes.end (), std::ostream_iterator<ShapeKeeper> (ostream));

  std::cout <<"Left-Right:\n";
  std::sort (shapes.begin (), shapes.end (), [](const ShapeKeeper & shape1, const ShapeKeeper & shape2) {
    return (*shape1.shape_).isMoreLeft (*shape2.shape_);
  });
  std::copy (shapes.begin (), shapes.end (), std::ostream_iterator<ShapeKeeper> (ostream));

  std::cout <<"Right-Left:\n";
  std::sort (shapes.begin (), shapes.end (), [](const ShapeKeeper & shape1, const ShapeKeeper & shape2) {
    return !(*shape1.shape_).isMoreLeft (*shape2.shape_);
  });
  std::copy (shapes.begin (), shapes.end (), std::ostream_iterator<ShapeKeeper> (ostream));

  std::cout <<"Top-Bottom:\n";
  std::sort (shapes.begin (), shapes.end (), [](const ShapeKeeper & shape1, const ShapeKeeper & shape2) {
    return (*shape1.shape_).isUpper (*shape2.shape_);
  });
  std::copy (shapes.begin (), shapes.end (), std::ostream_iterator<ShapeKeeper> (ostream));

  std::cout <<"Bottom-Top:\n";
  std::sort (shapes.begin (), shapes.end (), [](const ShapeKeeper & shape1, const ShapeKeeper & shape2) {
    return !(*shape1.shape_).isUpper (*shape2.shape_);
  });
  std::copy (shapes.begin (), shapes.end (), std::ostream_iterator<ShapeKeeper> (ostream));

}
