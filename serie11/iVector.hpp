#ifndef _IVECTOR_
#define _IVECTOR_

#include <cassert>

class iVector {
private:
  int len;
  int* coeff;

public:
  iVector ();
  iVector (int n, int fill = 0);
  iVector (const iVector& orig);
  ~iVector ();
  iVector& operator=(const iVector& orig);

  int getCoefficient(int i);
  void setCoefficient(int i, int x);
  int getLength();
};

#endif /* end of include guard: _IVECTOR_ */
