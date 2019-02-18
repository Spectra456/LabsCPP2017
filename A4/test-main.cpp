#define BOOST_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "CompositeShape.hpp"
#include "MatrixShape.hpp"

BOOST_AUTO_TEST_SUITE(RECTANGLE_TEST)

BOOST_AUTO_TEST_CASE(MOVE_SIZE)
{
  Rectangle rectangle({0, 0}, 4, 8);
  rectangle.move(10, 20);
  
  BOOST_CHECK_CLOSE(rectangle.getWidth(), 4, 0.0001);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 8, 0.0001);
}

BOOST_AUTO_TEST_CASE(MOVE_AREA)
{
  Rectangle rectangle({10, 10}, 5, 3);
  rectangle.move({0, 0});
  
  BOOST_CHECK_CLOSE(rectangle.getArea(), 15, 0.0001);
}

BOOST_AUTO_TEST_CASE(SCALE_SIZE)
{
  Rectangle rectangle({5, 2}, 7, 1);
  rectangle.scale(0.5);
  
  BOOST_CHECK_CLOSE(rectangle.getWidth(), 3.5, 0.0001);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 0.5, 0.0001);
}

BOOST_AUTO_TEST_CASE(SCALE_AREA)
{
  Rectangle rectangle({0, 0}, 2, 3);;
  rectangle.scale(2);
  
  BOOST_CHECK_CLOSE(rectangle.getArea(), 24, 0.0001);
}

BOOST_AUTO_TEST_CASE(ROTATE_SIZE)
{
  Rectangle rectangle({0, 10}, 5, 8);
  rectangle.rotate(90);
  
  BOOST_CHECK_CLOSE(rectangle.getWidth(), 5, 0.0001);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 8, 0.0001);
}

BOOST_AUTO_TEST_CASE(ROTATE_AREA)
{
  Rectangle rectangle({0, 0}, 2, 3);
  rectangle.rotate(120);
  
  BOOST_CHECK_CLOSE(rectangle.getArea(), 6, 0.0001);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TRIANGLE_TEST)

BOOST_AUTO_TEST_CASE(MOVE_CENTER)
{
  Triangle triangle({-3, 0}, {0, 9}, {3, 0});
  triangle.move(5, 6);
  
  BOOST_CHECK_CLOSE(triangle.getCenter().x, 5, 0.0001);
  BOOST_CHECK_CLOSE(triangle.getCenter().y, 9, 0.0001);
}

BOOST_AUTO_TEST_CASE(MOVE_AREA)
{
  Triangle triangle({0, 0}, {0, 2}, {3, 0});
  triangle.move({7, 3});
  
  BOOST_CHECK_CLOSE(triangle.getArea(), 3, 0.0001);
}

BOOST_AUTO_TEST_CASE(SCALE_CENTER)
{
  Triangle triangle({1, 0}, {2, 3}, {3, 0});
  triangle.scale(3);
  
  BOOST_CHECK_CLOSE(triangle.getCenter().x, 2, 0.0001);
  BOOST_CHECK_CLOSE(triangle.getCenter().y, 1, 0.0001);
}

BOOST_AUTO_TEST_CASE(SCALE_AREA)
{
  Triangle triangle({1, -1}, {3, -1}, {1, -3});
  triangle.scale(2);
  
  BOOST_CHECK_CLOSE(triangle.getArea(), 8, 0.0001);
}

BOOST_AUTO_TEST_CASE(ROTATE_CENTER)
{
  Triangle triangle({-2, 0}, {0, 3}, {2, 0});
  triangle.rotate(0);
  
  BOOST_CHECK_CLOSE(triangle.getCenter().x, 0, 0.0001);
  BOOST_CHECK_CLOSE(triangle.getCenter().y, 1, 0.0001);
}

BOOST_AUTO_TEST_CASE(ROTATE_AREA)
{
  Triangle triangle({0, 0}, {0, 5}, {2, 0});
  triangle.rotate(270);
  
  BOOST_CHECK_CLOSE(triangle.getArea(), 5, 0.0001);
}

BOOST_AUTO_TEST_CASE(INVALID_CONSTRUCTOR)
{ 
  BOOST_CHECK_THROW(Triangle triangle({1, 0}, {2, 0}, {3, 0}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(INVALID_SCALE)
{
  Triangle triangle({6, 2}, {0, 3}, {5, 2});

  BOOST_CHECK_THROW(triangle.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ROTATION_TEST)

BOOST_AUTO_TEST_CASE(RECTANGLE)
{
  Rectangle rectangle({10, 0}, 3, 3);
  rectangle.rotate(-45);

  rectangle_t frame_rect = rectangle.getFrameRect();
  
  BOOST_CHECK_CLOSE(frame_rect.pos.x, 10, 0.0001);
  BOOST_CHECK_CLOSE(frame_rect.pos.y, 0, 0.0001);
  BOOST_CHECK_CLOSE(frame_rect.width, 3 * sqrt(2), 0.0001);
  BOOST_CHECK_CLOSE(frame_rect.height, 3 * sqrt(2), 0.0001);
}

BOOST_AUTO_TEST_CASE(TRIANGLE)
{
  Triangle triangle({0, 0}, {0, 2}, {2, 0});
  triangle.rotate(360);

  rectangle_t frame_rect = triangle.getFrameRect();
  
  BOOST_CHECK_CLOSE(frame_rect.pos.x, 1, 0.0001);
  BOOST_CHECK_CLOSE(frame_rect.pos.y, 1, 0.0001);
  BOOST_CHECK_CLOSE(frame_rect.width, 2, 0.0001);
  BOOST_CHECK_CLOSE(frame_rect.height, 2, 0.0001);
}

BOOST_AUTO_TEST_CASE(COMPOSITE_SHAPE)
{
  auto rectangle_1 = std::make_shared<Rectangle>(point_t{-3, -5}, 4, 4);
  auto rectangle_2 = std::make_shared<Rectangle>(point_t{4, 2}, 4, 4);
  CompositeShape composite_shape(rectangle_1);
  composite_shape.addShape(rectangle_2);
  composite_shape.rotate(90);
  rectangle_t frame_rect = composite_shape.getFrameRect();
  
  BOOST_CHECK_CLOSE(frame_rect.pos.x, 0.5, 0.0001);
  BOOST_CHECK_CLOSE(frame_rect.pos.y, -1.5, 0.0001);
  BOOST_CHECK_CLOSE(frame_rect.width, 11, 0.0001);
  BOOST_CHECK_CLOSE(frame_rect.height, 11, 0.0001);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(MATRIX_SHAPE_TEST)

BOOST_AUTO_TEST_CASE(NEW_ROWS)
{
  auto rectangle = std::make_shared<Rectangle>(point_t{-3, -1}, 4, 4);
  auto circle = std::make_shared<Circle>(point_t{-1, 0}, 2);
  auto triangle = std::make_shared<Triangle>(point_t{4, 2}, point_t{6, -2}, point_t{2, -1});
  MatrixShape matrix_shape(rectangle);
  matrix_shape.addShape(circle);
  matrix_shape.addShape(triangle);
  
  BOOST_CHECK(matrix_shape[1][0] == circle);
}

BOOST_AUTO_TEST_CASE(NEW_COLUMNS)
{
  auto rectangle_1 = std::make_shared<Rectangle>(point_t{-2, 2}, 2, 2);
  auto rectangle_2 = std::make_shared<Rectangle>(point_t{0, 0}, 2, 2);
  auto rectangle_3 = std::make_shared<Rectangle>(point_t{2, -2}, 2, 2);
  MatrixShape matrix_shape(rectangle_1);
  matrix_shape.addShape(rectangle_2);
  matrix_shape.addShape(rectangle_3);
  
  BOOST_CHECK(matrix_shape[0][2] == rectangle_3);
}

BOOST_AUTO_TEST_CASE(ADD_1_SHAPE)
{
  auto triangle = std::make_shared<Triangle>(point_t{0, 0}, point_t{0, 5}, point_t{8, 0});
  MatrixShape matrix_shape(triangle);
  
  BOOST_CHECK(matrix_shape[0][0] == triangle);
}

BOOST_AUTO_TEST_CASE(ADD_COMPOSITE_SHAPE)
{
  auto rectangle_1 = std::make_shared<Rectangle>(point_t{0, 3}, 4, 2);
  auto rectangle_2 = std::make_shared<Rectangle>(point_t{-1, -1}, 2, 2);
  auto circle = std::make_shared<Circle>(point_t{0, 2}, 2);
  auto composite_shape_1 = std::make_shared<CompositeShape>(rectangle_1);
  composite_shape_1 -> addShape(circle);
  auto composite_shape_2 = std::make_shared<CompositeShape>(composite_shape_1);
  MatrixShape matrix_shape(composite_shape_1);
  matrix_shape.addShape(composite_shape_2);

  BOOST_CHECK(matrix_shape[0][0] == composite_shape_1 && matrix_shape[1][0] == composite_shape_2);
}

BOOST_AUTO_TEST_CASE(INVALID_CONSTRUCTOR)
{ 
  BOOST_CHECK_THROW(MatrixShape matrix_shape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(INVALID_ADD_SHAPE)
{
  auto triangle = std::make_shared<Triangle>(point_t{-2, 3}, point_t{0, 5}, point_t{5, -2});
  MatrixShape matrix_shape(triangle);
  
  BOOST_CHECK_THROW(matrix_shape.addShape(nullptr), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
