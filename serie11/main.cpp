#include "fraction.hpp"
#include <iostream>

int main() {
  Fraction f(7,5);
  f.print();
  f.reduce();
  f.print();

  std::cout << (double)f << '\n';
  Fraction g = 2.145;
  g.print();
  std::cout << "+\t-\t*\t/\t" << '\n';
  std::cout << f+g << "\t" << f-g << "\t" << f*g << "\t" << f/g << '\n';

  return 0;
}
