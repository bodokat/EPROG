#include "matrix.hpp"

using namespace std;

Matrix::Matrix () {
  this->dim = 0;
  this->type = 'F';
  this->coeff = (double*) 0;
}
Matrix::Matrix (char type, int dim, double fill) {
  assert(type == 'F' || type == 'L' || type == 'U');
  this->type = type;
  this->dim = dim;

  int len;
  if (type == 'F') {
    len = dim*dim;
  } else if (type == 'L' || type == 'U') {
    len = dim*(dim+1)/2;
  }

  this->coeff = new double[len];
  for (int i = 0; i < len; i++) {
    this->coeff[i] = fill;
  }
}
Matrix::Matrix (char type, int dim, double lb, double ub) {
  this->type = type;
  this->dim = dim;
  int len;
  if (type == 'F') {
    len = dim*dim;
  } else if (type == 'L' || type == 'U') {
    len = dim*(dim+1)/2;
  }
  coeff = new double[len];

  srand(time(NULL));
  for (int i = 0; i < len; i++) {

    double rnd = (double)rand() / RAND_MAX;
    coeff[i] = lb + rnd*(ub-lb);
  }
}
Matrix::Matrix (const Matrix& orig) {
  type = orig.type;
  dim = orig.dim;

  int len;
  if (type == 'F') {
    len = dim*dim;
  } else if (type == 'L' || type == 'U') {
    len = dim*(dim+1)/2;
  }

  coeff = new double[len];
  for (int i = 0; i < len; i++) {
    coeff[i] = orig.coeff[i];
  }
}
Matrix& Matrix::operator=(const Matrix& rhs) {
  if (this != &rhs) {
    type = rhs.type;
    dim = rhs.dim;

    int len;
    if (type == 'F') {
      len = dim*dim;
    } else if (type == 'L' || type == 'U') {
      len = dim*(dim+1)/2;
    }

    coeff = new double[len];
    for (int i = 0; i < len; i++) {
      coeff[i] = rhs.coeff[i];
    }
  }
  return *this;
}
Matrix::~Matrix () {
  if (dim > 0) {
    delete[] coeff;
  }
}


int Matrix::getDimension() const { return dim; }
char Matrix::getType() const { return type; }

double Matrix::getCoefficient(int j, int k) const {
  assert(j < dim && k < dim);
  if (type == 'F') {
    return coeff[j + k*dim];
  } else if (type == 'L') {
    if (j >= k) {
      return coeff[j*(j+1)/2 + k];
    } else {
      return 0;
    }
  } else if (type == 'U') {
    if (j <= k) {
      return coeff[k*(k+1)/2 + j];
    } else {
      return 0;
    }
  }
}
void Matrix::setCoefficient(int j, int k, double x) {
  assert(j < dim && k < dim);
  if (type == 'F') {
    coeff[j + k*dim] = x;
  } else if (type == 'L') {
    assert(j >= k);
    coeff[j*(j+1)/2 + k] = x;
  } else if (type == 'U') {
    assert(j <= k);
    coeff[k*(k+1)/2 + j] = x;
  }
}

void Matrix::scanMatrix(char t, int n) {
  assert(t == 'F' || t == 'L' || t == 'U');
  dim = n;
  this->type = t;

  if (dim != 0) {
    delete[] coeff;
  }
  int len;
  if (type == 'F') {
    len = dim*dim;
  } else if (type == 'L' || type == 'U') {
    len = dim*(dim+1)/2;
  }
  coeff = new double[len];

  if (type == 'F') {
    for (int j = 0; j < dim; j++) {
      cout << "Zeile " << j << ":" << endl;
      for (int k = 0; k < dim; k++) {
        double x;
        cin >> x;
        setCoefficient(j,k,x);
      }
    }
  } else if (type == 'U') {
    for (int j = 0; j < dim; j++) {
      cout << "Zeile " << j << ":" << endl;
      for (int k = j; k < dim; k++) {
        double x;
        cin >> x;
        setCoefficient(j,k,x);
      }
    }
  } else if (type == 'L') {
    for (int j = 0; j < dim; j++) {
      cout << "Zeile " << j << ":" << endl;
      for (int k = 0; k <= j; k++) {
        double x;
        cin >> x;
        setCoefficient(j,k,x);
      }
    }
  }
}
void Matrix::printMatrix() const {
  for (int j = 0; j < dim; j++) {
    for (int k = 0; k < dim; k++) {
      cout << getCoefficient(j,k) << " ";
    }
    cout << endl;
  }
}
double Matrix::columnSumNorm() const {
  double max = 0;

  for (int k = 0; k < dim; k++) {
    double sum = 0;
    for (int j = 0; j < dim; j++) {
      sum += fabs(getCoefficient(j,k));
    }
    if (sum > max) {
      max = sum;
    }
  }
  return max;
}
double Matrix::rowSumNorm() const {
  double max = 0;

  for (int j = 0; j < dim; j++) {
    double sum = 0;
    for (int k = 0; k < dim; k++) {
      sum += fabs(getCoefficient(j,k));
    }
    if (sum > max) {
      max = sum;
    }
  }
  return max;
}

const Vector operator*(const Matrix& m, const Vector& v) {
  assert(m.getDimension() == v.size());
  int n = m.getDimension();
  Vector res(n);
  for (int j = 0; j < n; j++) {
    double xj = 0; //j-ter Eintrag des Vektors
    for (int k = 0; k < n; k++) {
      xj += m.getCoefficient(j,k) * v.get(k);
    }
    res.set(j,xj);
  }
  return res;
}
