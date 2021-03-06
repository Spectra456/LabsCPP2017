#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include "MatrixShape.hpp"

MatrixShape::MatrixShape(const std::shared_ptr<Shape> &shape):
matrix_(new std::shared_ptr<Shape>[1]),
rows_(1),
columns_(1)
{
  if (shape == nullptr)
    {
    throw std::invalid_argument("invalid pointer");
    }

  matrix_[0] = shape;
}

MatrixShape::MatrixShape(const MatrixShape &matrix_shape):
rows_(matrix_shape.rows_),
columns_(matrix_shape.columns_)
{
  std::unique_ptr <std::shared_ptr<Shape>[]> matrix_copy(new std::shared_ptr<Shape>[rows_ * columns_]);

  for (size_t i = 0; i < (rows_ * columns_); i ++)
    {
    matrix_copy[i] = matrix_shape.matrix_[i];
    }

  matrix_.swap(matrix_copy);
}

MatrixShape & MatrixShape::operator=(const MatrixShape &matrix_shape)
{
  if (this != &matrix_shape)
    {
    rows_ = matrix_shape.rows_;
    columns_ = matrix_shape.columns_;
    std::unique_ptr <std::shared_ptr<Shape>[]> matrix_copy(new std::shared_ptr<Shape>[rows_ * columns_]);

    for (size_t i = 0; i < (rows_ * columns_); i ++)
      {
      matrix_copy[i] = matrix_shape.matrix_[i];
      }

    matrix_.swap(matrix_copy);
    }

  return *this;
}

std::unique_ptr <std::shared_ptr<Shape>[]>::pointer MatrixShape::operator[](const size_t &index) const
{
  if (index > rows_)
    {
    throw std::invalid_argument("index out of range");
    }

  return matrix_.get() + index * columns_;
}

void MatrixShape::addShape(const std::shared_ptr<Shape> &shape)
{
  if (shape == nullptr)
    {
    throw std::invalid_argument("invalid pointer");
    }

  size_t i = rows_ * columns_;
  size_t desired_row = 1;

  while (i > 0)
    {
    i --;

    if (checkOverlap(matrix_[i], shape))
      {
      desired_row = i / columns_ + 2;
      }
    }

  size_t rows_temp = rows_;
  size_t columns_temp = columns_;
  size_t free_columns = 0;

  if (desired_row > rows_)
    {
    rows_temp ++;
    free_columns = columns_;
    }
  else
    {
    size_t j = (desired_row - 1) * columns_;
    while (j < (desired_row * columns_))
      {
      if (matrix_[j] == nullptr)
        {
        free_columns ++;
        }

      j ++;
      }

    if (free_columns == 0)
      {
      columns_temp ++;
      free_columns = 1;
      }
    }

  std::unique_ptr <std::shared_ptr<Shape>[]> matrix_temp(new std::shared_ptr<Shape>[rows_temp * columns_temp]);

  for (size_t i = 0; i < rows_temp; i ++)
    {
    for (size_t j = 0; j < columns_temp; j ++)
      {
      if (i >= rows_ || j >= columns_)
        {
        matrix_temp[i * columns_temp + j] = nullptr;
        continue;
        }

      matrix_temp[i * columns_temp + j] = matrix_[i * columns_ + j];
      }
    }

  matrix_temp[desired_row * columns_temp - free_columns] = shape;

  matrix_.swap(matrix_temp);
  rows_ = rows_temp;
  columns_ = columns_temp;
}

bool MatrixShape::checkOverlap(const std::shared_ptr<Shape> &shape_1, const std::shared_ptr<Shape> &shape_2) const
{
  if (shape_1 == nullptr || shape_2 == nullptr)
    {
    return false;
    }

  rectangle_t shape_1_frame_rect = shape_1 -> getFrameRect();
  rectangle_t shape_2_frame_rect = shape_2 -> getFrameRect();

  return ((fabs(shape_1_frame_rect.pos.x - shape_2_frame_rect.pos.x)
           < ((shape_1_frame_rect.width / 2) + (shape_2_frame_rect.width / 2)))
          && ((fabs(shape_1_frame_rect.pos.y - shape_2_frame_rect.pos.y)
               < ((shape_1_frame_rect.height / 2) + (shape_2_frame_rect.height / 2)))));
}

void MatrixShape::print() const
{
  for (size_t i = 0; i < rows_; i ++)
    {
    for (size_t j = 0; j < columns_; j ++)
      {
      if (matrix_[i * columns_ + j] != nullptr)
        {
        std::cout << std::setw(16) << std::left << matrix_[i * columns_ + j] -> getName();
        }
      }

    std::cout << "\n";
    }
}

size_t MatrixShape::getColumns() const
{
  return columns_;
}
