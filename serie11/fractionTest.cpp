#include "fraction.hpp"
#include <iostream>

int main() {
  Fraction f(250,5);
  f.print();
  f.reduce();
  f.print();

  std::cout << (double)f << '\n';
  Fraction g = 2.145;
  g.print();
  std::cout << "+\t-\t*\t/\t" << '\n';
  std::cout << f+g << "\t" << f-g << "\t" << f*g << "\t" << f/g << '\n';

  Fraction a1(2.4);
  Fraction a2(2.5);
  Fraction a3(2.6);
  std::cout << "a1: " << a1 << "\ta2: " << a2 << "\ta3: " << a3 << '\n';
  std::cout << "a1: " << (int)a1 << "\ta2: " << (int)a2 << "\ta3: " << (int)a3 << '\n';

  return 0;
}
