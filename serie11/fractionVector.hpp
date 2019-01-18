#ifndef _FRACTIONVECTOR_
#define _FRACTIONVECTOR_

#include "fraction.hpp"

class FractionVector {
private:
  int len;
  Fraction* coeff;

public:
  FractionVector ();
  FractionVector (int len, Fraction fill = 0);
  FractionVector (const FractionVector& orig);
  ~FractionVector ();

  operator=(const FractionVector& orig);

  void setCoefficient(int j, Fraction x);
  Fraction getCoefficient(int j);
  int getLength();
};

#endif /* end of include guard: _FRACTIONVECTOR_ */
