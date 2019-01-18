#include <iostream>
#include <cassert>
using std::cout;

class Fraction {
  private:
    int numerator;
    int denominator;
  public:
    int getNumerator();
    int getDenominator();
    void setNumerator(int n);
    void setDenominator(int n);
    void print();
};
