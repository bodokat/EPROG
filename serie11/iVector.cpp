#include "iVector.hpp"

iVector::iVector () {
  len = 0;
  coeff = (int*) 0;
}
iVector::iVector (int n, int fill) {
  assert(n >= 0);
  len = n;
  if (n > 0) {
    coeff = new int[len];
    for (int i = 0; i < len; i++) {
      coeff[i] = fill;
    }
  } else {
    coeff = (int*) 0;
  }
}
iVector::iVector (const iVector& orig) {
  len = orig.len;
  if (len > 0) {
    coeff = new int[len];
    for (int i = 0; i < len; i++) {
      coeff[i] = orig.coeff[i];
    }
  } else {
    coeff = (int*) 0;
  }
}
iVector::~iVector () {
  if (len > 0) {
    delete[] coeff;
  }
}
iVector& iVector::operator=(const iVector& orig) {
  len = orig.len;
  if (len > 0) {
    coeff = new int[len];
    for (int i = 0; i < len; i++) {
      coeff[i] = orig.coeff[i];
    }
  } else {
    coeff = (int*) 0;
  }
  return *this;
}

int iVector::getCoefficient(int i) {
  assert(i < len);
  return coeff[i];
}
void iVector::setCoefficient(int i, int x) {
  assert(i < len);
  coeff[i] = x;
}
int iVector::getLength() { return len; }
