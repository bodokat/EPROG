#include "matrix.hpp"
#include "vector_first.hpp"

Vector solveU(const Matrix& U, const Vector& x) {
  assert(U.getDimension() == x.size());
  assert(U.getType() == 'U');
  int n = U.getDimension();
  Vector res(n);
  for (int j = n - 1; j >= 0; j--) {
    double sum = 0;
    for (int k = j+1; k < n; k++) {
      sum += U.getCoefficient(j,k)*res.get(k);
    }
    res.set(j, (x.get(j) - sum)/U.getCoefficient(j,j));
  }
  return res;
}
