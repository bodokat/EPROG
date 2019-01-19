#include "iVector.hpp"
#include <iostream>

// gibt iVector mit Primzahlen von 2 bis n zurueck
iVector eratosthenes(int n);

iVector primfaktoren(int input) {
  iVector prim = eratosthenes(input);
  int n = prim.getLength();

  iVector fakt(n);
  int anzahlFakt = 0;
  int j = 0;
  int M = input;
  for (int i = 0; i < n; i++) {
    int p = prim.getCoefficient(i);
    if (M % p == 0) {
      M /= p;
      fakt.setCoefficient(j,p);
      anzahlFakt++;
      i--;
      j++;
    }
  }

  iVector result(anzahlFakt);
  for (int i = 0; i < anzahlFakt; i++) {
    result.setCoefficient(i, fakt.getCoefficient(i));
  }
  return result;
}

iVector eratosthenes(int n) {
  int anzahl = 0;
  int* nums = new int[n-1];

  for(int i = 0; i < n-1; i++) {
    nums[i] = i + 2;
  }


  for(int i = 0; i < n-1; i++) {
    if(nums[i]) {
      anzahl++;
      for(int j = 2*nums[i]; j <= n; j += nums[i]) {
        nums[j-2] = 0;
      }
    }
  }

  iVector prim(anzahl);
  int j = 0;
  for (int i = 0; i < n-1; i++) {
    if (nums[i]) {
      prim.setCoefficient(j,nums[i]);
      j++;
    }
  }
  return prim;
}

int main() {
  int x;
  std::cin >> x;
  std::cout << "Primfaktoren von " << x << ":" << '\n';
  iVector fakt = primfaktoren(x);
  for (int i = 0; i < fakt.getLength(); i++) {
    std::cout << fakt.getCoefficient(i) << '\n';
  }

  return 0;
}
