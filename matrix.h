#pragma once

#include <vector>
#include <iostream>



using namespace std;

class Matrix {
public:
  Matrix();
  ~Matrix();
  Matrix dot_product(Matrix B);
  Matrix inverse();
  Matrix minors();
  Matrix cofactors();
  Matrix transpose();
  Matrix multiply(float scalar);
  float determinant();
  vector< vector<float> > matrix;
  void inspect();
};

int mymod(int n, int b);
