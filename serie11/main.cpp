#include "fraction.hpp"
#include <iostream>

int main() {
  Fraction f(1029,1071);
  f.print();
  f.reduce();
  f.print();

  return 0;
}
