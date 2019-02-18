#define BOOST_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "Rectangle.hpp"
#include "Circle.hpp"

BOOST_AUTO_TEST_SUITE(RECTANGLE_TEST)

BOOST_AUTO_TEST_CASE(MOVE_WIDTH)
{
  Rectangle shape({0, 0}, 4, 8);
  Shape *rectangle = &shape;
  rectangle -> move({10, 20});

  BOOST_CHECK_CLOSE(shape.getWidth(), 4, 0.0001);
}

BOOST_AUTO_TEST_CASE(MOVE_HEIGHT)
{
  Rectangle shape({0, 0}, 10, 2);
  Shape *rectangle = &shape;
  rectangle -> move({0, 0});

  BOOST_CHECK_CLOSE(shape.getHeight(), 2, 0.0001);
}

BOOST_AUTO_TEST_CASE(MOVE_AREA)
{
  Rectangle shape({10, 10}, 5, 3);
  Shape *rectangle = &shape;
  rectangle -> move({0, 0});

  BOOST_CHECK_CLOSE(rectangle -> getArea(), 15, 0.0001);
}

BOOST_AUTO_TEST_CASE(SCALE_AREA)
{
  Rectangle shape({0, 0}, 2, 3);
  Shape *rectangle = &shape;
  rectangle -> scale(2);

  BOOST_CHECK_CLOSE(rectangle -> getArea(), 24, 0.0001);
}

BOOST_AUTO_TEST_CASE(INVALID_WIDTH)
{
  BOOST_CHECK_THROW(Rectangle shape({0, 0}, -10, 3), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(INVALID_HEIGHT)
{
  BOOST_CHECK_THROW(Rectangle shape({0, 0}, 5, 0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(INVALID_SCALE)
{
  Rectangle shape({0, 0}, 10, 10);
  Shape *rectangle = &shape;

  BOOST_CHECK_THROW(rectangle -> scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(CIRCLE_TEST)

BOOST_AUTO_TEST_CASE(MOVE_RADIUS)
{
  Circle shape({0, 0}, 3);
  Shape *circle = &shape;
  circle -> move({30, 10});

  BOOST_CHECK_CLOSE(shape.getRadius(), 3, 0.0001);
}

BOOST_AUTO_TEST_CASE(MOVE_AREA)
{
  Circle shape({0, 0}, 5);
  Shape *circle = &shape;
  circle -> move({5, 20});

  BOOST_CHECK_CLOSE(circle -> getArea(), M_PI * 25, 0.0001);
}

BOOST_AUTO_TEST_CASE(SCALE_AREA)
{
  Circle shape({0, 0}, 5);
  Shape *circle = &shape;
  circle -> scale(2);

  BOOST_CHECK_CLOSE(circle -> getArea(), M_PI * 100, 0.0001);
}

BOOST_AUTO_TEST_CASE(INVALID_RADIUS)
{
  BOOST_CHECK_THROW(Circle shape({0, 0}, -1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(INVALID_SCALE)
{
  Circle shape({0, 0}, 1);
  Shape *circle = &shape;
  BOOST_CHECK_THROW(circle -> scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
