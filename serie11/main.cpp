#include "fraction.hpp"
#include <iostream>

int main() {
  Fraction f(1029,1071);
  f.print();
  f.reduce();
  f.print();

  std::cout << (double)f << '\n';
  Fraction g = 3.45;
  g.print();

  return 0;
}
