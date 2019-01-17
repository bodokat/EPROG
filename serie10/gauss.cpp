#include "matrix.hpp"
#include "vector_first.hpp"

Matrix eliminate(const Matrix& M, Vector& x);
Vector solveU(const Matrix& U, const Vector& x);

Vector solve(const Matrix& M, Vector& x) {
  assert(M.getDimension() == x.size());

  //Elimination
  Matrix A = eliminate(M,x);
  //Solve
  return solveU(A,x);
}



Matrix eliminate(const Matrix& M, Vector& x) {
  int n = M.getDimension();
  Matrix U('U',n);

  for (int k = 0; k < n; k++) {
    U.setCoefficient(0,k,M.getCoefficient(0,k)); //kopiere 0-te Zeile
  }

  //fuer jede Zeile j wird fuer jede darunterliegende Zeile jo (j*factor) von jo abgezogen
  for (int j = 0; j < n; j++) {
    assert(U.getCoefficient(j,j) != 0);

    for (int jo = j+1; jo < n; jo++) {
      double factor = M.getCoefficient(jo,j)/U.getCoefficient(j,j);

      x.set(jo, x.get(jo) - x.get(j)*factor);
      for (int k = jo; k < n; k++) {
        U.setCoefficient(jo,k,M.getCoefficient(jo,k) - U.getCoefficient(j,k)*factor);
      }
    }
  }

  return U;
}
