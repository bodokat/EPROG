#include "vector_first.hpp"

Vector::Vector() {
  dim = 0;
  coeff = (double * ) 0;
}
Vector::Vector(int dim, double init) {
  assert(dim>0);

  this->dim = dim;
  coeff = (double * ) malloc(dim * sizeof(double));
  assert(coeff != (double * ) 0);
  for (int j=0; j<dim; ++j) {
    coeff[j] = init;
  }
}
Vector::Vector(const Vector& rhs) {
  dim = rhs.dim;
  coeff = (double * ) malloc(dim * sizeof(double));
  assert(coeff != (double * ) 0);
  for (int j=0; j<dim; ++j) {
    coeff[j] = rhs.coeff[j];
  }
}

Vector::~Vector() {
  if (dim > 0) {
    free(coeff);
  }
}

int Vector::size() const {
  return dim;
}

void Vector::set(int k, double value) {
  assert(k>=0 && k<dim);
  coeff[k] = value;
}

double Vector::get(int k) const {
  assert(k>=0 && k<dim);
  return coeff[k];
}

double Vector::norm() const {
  double norm = 0;
  for (int j=0; j<dim; ++j) {
    norm = norm + coeff[j] * coeff[j];
  }
  return sqrt(norm);
}

Vector& Vector::operator=(const Vector& rhs) {
  if (this != &rhs) {
    if (dim != rhs.dim) {
      if (dim > 0) {
        delete[] coeff;
      }
      dim = rhs.dim;
      if (dim > 0) {
        coeff = new double[dim];
      }
      else {
        coeff = (double * ) 0;
      }
    }
    for (int j=0; j<dim; ++j) {
      coeff[j] = rhs.coeff[j];
    }
  }
  return * this;
}
