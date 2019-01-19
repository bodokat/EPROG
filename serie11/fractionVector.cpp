#include "fractionVector.hpp"

FractionVector::FractionVector () {
  len = 0;
  coeff = (Fraction*) 0;
}
FractionVector::FractionVector (int len, Fraction fill) {
  assert(len >= 0);
  this->len = len;
  if (len > 0) {
    coeff = new Fraction[len];
    for (int i = 0; i < len; i++) {
      coeff[i] = fill;
    }
  }
}
FractionVector::FractionVector (const FractionVector& orig) {
  len = orig.len;
  if (len > 0) {
    coeff = new Fraction[len];
    for (int i = 0; i < len; i++) {
      coeff[i] = orig.coeff[i];
    }
  }
}
FractionVector::~FractionVector (){
  if (len > 0) {
    delete[] coeff;
  }
}

FractionVector& FractionVector::operator=(const FractionVector& orig) {
  len = orig.len;
  if (len > 0) {
    coeff = new Fraction[len];
    for (int i = 0; i < len; i++) {
      coeff[i] = orig.coeff[i];
    }
  }
}

void FractionVector::setCoefficient(int j, Fraction x) {
  assert(j < len);
  coeff[j] = x;
}
Fraction FractionVector::getCoefficient(int j) {
  assert(j < len);
  return coeff[j];
}
int FractionVector::getLength() { return len; }

// Sort method
void Quicksort(Fraction* arr, int min, int max) {
  if (min >= max) { return; }

  int left = min + 1;
  int right = max;
  int mid = min + (max - min)/2;
  double pivot = (double) arr[mid];

  // Fraction temp;

  std::swap(arr[min],arr[mid]);
  do {
    while (left <= right && (double) arr[left] <= pivot) { left++; }
    while (left <= right && (double) arr[right] > pivot) { right--; }


    if (left < right) {
      std::swap(arr[left],arr[right]);
    }
  } while(left <= right);
  std::swap(arr[min],arr[right]);

  Quicksort(arr, min, right);
  Quicksort(arr, right + 1, max);
}
void FractionVector::sort() {
  //Quicksort
  Quicksort(coeff, 0, len - 1);
}
