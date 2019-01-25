#include "iVector.hpp"
#include <iostream>

int main() {
  iVector v1(3);
  iVector v2(3,2);

  std::cout << v1.getCoefficient(2) << '\n';
  std::cout << v2.getCoefficient(2) << '\n';
  std::cout << v2.getLength() << '\n';

  return 0;
}
