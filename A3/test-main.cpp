#define BOOST_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "CompositeShape.hpp"

BOOST_AUTO_TEST_SUITE(COMPOSITE_SHAPE_TEST)

BOOST_AUTO_TEST_CASE(FRAME_RECT_MOVE_POS)
{
  auto rectangle = std::make_shared<Rectangle>(point_t{0, 0}, 2, 4);
  auto circle = std::make_shared<Circle>(point_t{2, -2}, 2);
  CompositeShape composite_shape(rectangle);
  composite_shape.addShape(circle);
  composite_shape.move(2, 2);
  
  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().pos.x, 3.5, 0.0001);
  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().pos.y, 1, 0.0001);
}

BOOST_AUTO_TEST_CASE(FRAME_RECT_MOVE_SIZE)
{
  auto rectangle = std::make_shared<Rectangle>(point_t{2.5, 2}, 3, 2);
  auto circle = std::make_shared<Circle>(point_t{6, 4}, 1);
  CompositeShape composite_shape(rectangle);
  composite_shape.addShape(circle);
  composite_shape.move({10, 20});
  
  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().width, 6, 0.0001);
  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().height, 4, 0.0001);
}

BOOST_AUTO_TEST_CASE(MOVE_AREA)
{
  auto rectangle_1 = std::make_shared<Rectangle>(point_t{1.5, 3}, 3, 1);
  auto rectangle_2 = std::make_shared<Rectangle>(point_t{2.5, 3}, 3, 2);
  CompositeShape composite_shape(rectangle_1);
  composite_shape.addShape(rectangle_2);
  composite_shape.move({3, 6});
  
  BOOST_CHECK_CLOSE(composite_shape.getArea(), 9, 0.0001);
}

BOOST_AUTO_TEST_CASE(FRAME_RECT_SCALE_POS)
{
  auto rectangle = std::make_shared<Rectangle>(point_t{3, -2}, 2, 2);
  auto circle = std::make_shared<Circle>(point_t{0, 2}, 1);
  CompositeShape composite_shape(rectangle);
  composite_shape.addShape(circle);
  composite_shape.scale(2);

  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().pos.x, 1.5, 0.0001);
  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().pos.y, 0, 0.0001);
}

BOOST_AUTO_TEST_CASE(FRAME_RECT_SCALE_SIZE)
{
  auto rectangle = std::make_shared<Rectangle>(point_t{2, -2}, 2, 2);
  auto circle = std::make_shared<Circle>(point_t{-2, 2}, 1);
  CompositeShape composite_shape(rectangle);
  composite_shape.addShape(circle);
  composite_shape.scale(2);

  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().width, 12, 0.0001);
  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().height, 12, 0.0001);
}

BOOST_AUTO_TEST_CASE(SCALE_AREA)
{
  auto rectangle = std::make_shared<Rectangle>(point_t{-1, 0.5}, 4, 1);
  auto circle = std::make_shared<Circle>(point_t{-2, 3}, 1);
  CompositeShape composite_shape(rectangle);
  composite_shape.addShape(circle);
  double area = composite_shape.getArea();
  double x = 2;
  composite_shape.scale(x);

  BOOST_CHECK_CLOSE(composite_shape.getArea(), area * x * x, 0.0001);
}

BOOST_AUTO_TEST_CASE(INVALID_CONSTRUCTOR)
{ 
  BOOST_CHECK_THROW(CompositeShape composite_shape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(INVALID_ADD_SHAPE)
{
  auto circle = std::make_shared<Circle>(point_t{0, 0}, 3);
  CompositeShape composite_shape(circle);
  
  BOOST_CHECK_THROW(composite_shape.addShape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(INVALID_SCALE)
{
  auto rectangle = std::make_shared<Rectangle>(point_t{0, 0}, 5, 5);
  CompositeShape composite_shape(rectangle);

  BOOST_CHECK_THROW(composite_shape.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
