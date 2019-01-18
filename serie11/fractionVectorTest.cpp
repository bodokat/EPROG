#include "fraction.hpp"
#include "fractionVector.hpp"

int main() {
  FractionVector v1(3);
  FractionVector v2(4,2.5);
  std::cout << v1.getCoefficient(2) << '\n';
  std::cout << v2.getCoefficient(3) << '\n';


  return 0;
}
