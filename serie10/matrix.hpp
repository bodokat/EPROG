#ifndef _MATRIXH_
#define _MATRIXH_

#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include "vector_first.hpp"

class Matrix {
private:
  int dim;
  char type;
  double* coeff;

public:
  Matrix ();
  Matrix (char type, int dim, double fill = 0);
  Matrix (char type, int dim, double lb, double ub);
  Matrix (const Matrix& orig);
  ~Matrix ();
  Matrix& operator=(const Matrix& rhs);

  int getDimension() const;
  char getType() const;
  double getCoefficient(int j, int k) const;
  void setCoefficient(int j, int k, double x);

  void scanMatrix(char type, int n);
  void printMatrix() const;
  double columnSumNorm() const;
  double rowSumNorm() const;
};

const Vector operator*(const Matrix& m, const Vector& v);


#endif /* end of include guard: _MATRIXH_ */
