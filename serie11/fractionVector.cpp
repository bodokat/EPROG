#include "fractionVector.hpp"

FractionVector::FractionVector () {
  len = 0;
  coeff = (Fraction*) 0;
}
FractionVector::FractionVector (int len, Fraction fill) {
  assert(len >= 0);
  this->len = len;
  if (len > 0) {
    coeff = new Fraction[len];
    for (int i = 0; i < len; i++) {
      coeff[i] = fill;
    }
  }
}
FractionVector::FractionVector (const FractionVector& orig) {
  len = orig.len;
  if (len > 0) {
    coeff = new Fraction[len];
    for (int i = 0; i < len; i++) {
      coeff[i] = orig.coeff[i];
    }
  }
}
FractionVector::~FractionVector (){
  if (len > 0) {
    delete[] coeff;
  }
}

FractionVector::operator=(const FractionVector& orig) {
  len = orig.len;
  if (len > 0) {
    coeff = new Fraction[len];
    for (int i = 0; i < len; i++) {
      coeff[i] = orig.coeff[i];
    }
  }
}

void FractionVector::setCoefficient(int j, Fraction x) { coeff[j] = x; }
Fraction FractionVector::getCoefficient(int j) { return coeff[j]; }
int FractionVector::getLength() { return len; }
