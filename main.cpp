#include "matrix.h"
#include <cstdio>

int main()
{
  Matrix maj;
  vector<float> row[3];
  row[0].push_back(1); row[0].push_back(0); row[0].push_back(2);
  row[1].push_back(1); row[1].push_back(2); row[1].push_back(5);
  row[2].push_back(1); row[2].push_back(5); row[2].push_back(-1);
  for(int i=0; i<3; i++) maj.matrix.push_back(row[i]);

  printf("maj");
  maj.inspect();

  Matrix inverse = maj.inverse();
  printf("Inverse");
  inverse.inspect();

  cout << "Solving linear system" << endl;

  vector<float> brow;
  brow.push_back(6);brow.push_back(-4);brow.push_back(27);
  Matrix b;
  b.matrix.push_back(brow);

  cout << "Now:" << endl;

  Matrix x = inverse.dot_product(b);
  x.inspect();
}
