#pragma once
#ifndef Polynom_h
#define Polynom_h

#include <iostream>

struct Monom {
  double coeff;
  int degree;
  Monom* next;
};

class Polynom {
  Monom* head;
  int getX(int deg) const;
  int getY(int deg) const;
  int getZ(int deg) const;
  int makeDegree(int x, int y, int z) const;

 public:
  Polynom();
  ~Polynom();
  void addMonom(double coef, int degree);
  Polynom operator+(const Polynom& other) const;
  Polynom operator-(const Polynom& other) const;
  Polynom operator*(double sc) const;
  Polynom operator*(const Polynom& other) const;
  void print() const;
  bool operator==(const Polynom& other) const;
};

#endif