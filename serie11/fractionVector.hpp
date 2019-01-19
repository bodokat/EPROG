#ifndef _FRACTIONVECTOR_
#define _FRACTIONVECTOR_

#include "fraction.hpp"
#include <stdlib.h>
#include <cassert>

class FractionVector {
private:
  int len;
  Fraction* coeff;

public:
  FractionVector ();
  FractionVector (int len, Fraction fill = 0);
  FractionVector (const FractionVector& orig);
  ~FractionVector ();

  FractionVector& operator=(const FractionVector& orig);

  void setCoefficient(int j, Fraction x);
  Fraction getCoefficient(int j);
  int getLength();

  void sort();
};

#endif /* end of include guard: _FRACTIONVECTOR_ */
