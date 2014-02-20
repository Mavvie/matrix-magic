#include "matrix.h"
#include <cstdio>

int main()
{
  Matrix maj;
  vector<float> row[3];
  row[0].push_back(3); row[0].push_back(0); row[0].push_back(2);
  row[1].push_back(2); row[1].push_back(0); row[1].push_back(-2);
  row[2].push_back(0); row[2].push_back(1); row[2].push_back(1);
  for(int i=0; i<3; i++) maj.matrix.push_back(row[i]);

  printf("maj");
  maj.inspect();

  Matrix min = maj.minors();
  printf("min");
  min.inspect();

  Matrix cof = min.cofactors();
  printf("Cofactors");
  cof.inspect();

  Matrix transposed = cof.transpose();
  printf("Transposed");
  transposed.inspect();

  float det = maj.determinant();
  cout << "Determinant: " << det << endl;

  Matrix inverse = transposed.multiply(1.0f/det);
  printf("Inverse");
  inverse.inspect();

  inverse = maj.inverse();
  printf("Inverse");
  inverse.inspect();
}
