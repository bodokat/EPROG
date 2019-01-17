#include "matrix.hpp"
#include "vector_first.hpp"

#include <iostream>

using namespace std;

Vector solve(const Matrix& U, Vector& x);
Vector gausspivot(Matrix& M, Vector& x);

int main() {
  char typ;
  Matrix f('F',5,2);
  Matrix l('L',5,2);
  Matrix u('U',5,2);
  f.printMatrix();
  l.printMatrix();
  u.printMatrix();

  Matrix m;
  cout << "Typ: " << endl;
  cin >> typ;
  m.scanMatrix(typ,3);
  m.printMatrix();
  cout << "columnSumNorm: " << m.columnSumNorm() << endl;
  cout << "rowSumNorm: " << m.rowSumNorm() << endl;

  Vector v(m.getDimension());
  v.set(0,-1);
  v.set(1,0);
  v.set(2,1.5);
  for (size_t i = 0; i < 3; i++) {
    cout << "M*v[" << i << "]: " << (m*v).get(i) << endl;

  }

  Matrix ran('F',2,-5,5);
  ran.printMatrix();
  Vector x(2,3);

  Vector r = gausspivot(ran,x);
  cout << "Result: " << endl;
  for (int i = 0; i < 2; i++) {
    cout << r.get(i) << endl;
  }
  return 0;
}
