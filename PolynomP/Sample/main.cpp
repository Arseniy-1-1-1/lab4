#include <stdio.h>

#include <iostream>

#include "Polynom.h"

Polynom inputPoly() {
  Polynom p;
  int n;
  std::cout << "monom count: ";
  std::cin >> n;

  std::cout << "coeff x y z\n";

  for (int i = 0; i < n; i++) {
    double c;
    int x, y, z;
    std::cin >> c >> x >> y >> z;
    p.addMonom(c, x * 100 + y * 10 + z);
  }

  return p;
}

int main() {
  std::cout << "Hello\n";
  std::cout << "A:\n";
  Polynom A = inputPoly();
  std::cout << "B:\n";
  Polynom B = inputPoly();
  std::cout << "A+B:\n";
  Polynom C = A + B;
  C.print();

  return 0;
}
