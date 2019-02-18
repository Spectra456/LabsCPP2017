#ifndef MATRIXSHAPE_HPP_INCLUDED
#define MATRIXSHAPE_HPP_INCLUDED
#include <memory>
#include "Shape.hpp"

class MatrixShape
{
public:
  MatrixShape(const std::shared_ptr<Shape> &);
  MatrixShape(const MatrixShape &);
  MatrixShape(MatrixShape &&) = default;
  MatrixShape & operator=(const MatrixShape &);
  MatrixShape & operator=(MatrixShape&&) = default;
  std::unique_ptr <std::shared_ptr<Shape>[]>::pointer operator[](const size_t &index) const;
  void addShape(const std::shared_ptr<Shape> &);
  void print() const;
  size_t getColumns() const;
private:
  std::unique_ptr <std::shared_ptr<Shape>[]> matrix_;
  size_t rows_, columns_;
  bool checkOverlap(const std::shared_ptr<Shape> &, const std::shared_ptr<Shape> &) const;
};

#endif
