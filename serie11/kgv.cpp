#include <iostream>

int euclid(int a,int b) {
  while (b != 0) {
    int h = a % b;
    a = b;
    b = h;
  }
  return a;
}

int kgV(int a, int b) {
  return a*b/euclid(a,b);
}

int main() {
  int x,y;
  std::cin >> x;
  std::cin >> y;
  std::cout << "kgV(" << x << "," << y << ") = " << kgV(x,y) << '\n';

  return 0;
}
