#include "fraction.hpp"
#include "fractionVector.hpp"

int main() {
  FractionVector v1(6);
  FractionVector v2(4,2.5);
  std::cout << v1.getCoefficient(2) << '\n';
  std::cout << v2.getCoefficient(3) << '\n';

  v1.setCoefficient(0,Fraction(-1,2));
  v1.setCoefficient(1,Fraction(5,7));
  v1.setCoefficient(2,Fraction(1,3));
  v1.setCoefficient(3,Fraction(0,1));
  v1.setCoefficient(4,Fraction(11,2));
  v1.setCoefficient(5,Fraction(-7,8));

  std::cout << "-- Sort: --" << '\n';
  v1.sort();
  for (int i = 0; i < v1.getLength(); i++) {
    std::cout << v1.getCoefficient(i) << '\n';
  }


  return 0;
}
