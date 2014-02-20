#include "matrix.h"
#include <cstdio>

int main()
{
  // Matrix a;
  // vector<float> row1;
  // row1.push_back(1);row1.push_back(2);row1.push_back(3);
  // vector<float> row2;
  // row2.push_back(4);row2.push_back(5);row2.push_back(6);
  // a.matrix.push_back(row1);
  // a.matrix.push_back(row2);

  // Matrix b;
  // vector<float> rowa, rowb, rowc;
  // rowa.push_back(7); rowa.push_back(8);
  // rowb.push_back(9); rowb.push_back(10);
  // rowc.push_back(11); rowc.push_back(12);
  // b.matrix.push_back(rowa);
  // b.matrix.push_back(rowb);
  // b.matrix.push_back(rowc);

  // Matrix prices;
  // vector<float> p;
  // p.push_back(3);p.push_back(4);p.push_back(2);
  // prices.matrix.push_back(p);

  // Matrix sales;
  // vector<float> row[3];
  // row[0].push_back(13);row[0].push_back(9);row[0].push_back(7);row[0].push_back(15);
  // row[1].push_back(8);row[1].push_back(7);row[1].push_back(4);row[1].push_back(6);
  // row[2].push_back(6);row[2].push_back(4);row[2].push_back(0);row[2].push_back(3);
  // for(int i=0; i<3; i++) sales.matrix.push_back(row[i]);

  // Matrix a;
  // vector<float> row[3];
  // row[0].push_back(6); row[0].push_back(1); row[0].push_back(1);
  // row[1].push_back(4); row[1].push_back(-2); row[1].push_back(5);
  // row[2].push_back(2); row[2].push_back(8); row[2].push_back(7);
  // for(int i=0; i<3; i++) a.matrix.push_back(row[i]);

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
  printf("Other inverse");
  inverse.inspect();


  // Matrix t;
  // vector<float> row[2];
  // row[0].push_back(3); row[0].push_back(2);
  // row[1].push_back(2); row[1].push_back(-2);
  // t.matrix.push_back(row[0]);t.matrix.push_back(row[1]);

  // printf("T");
  // t.inspect();
  // printf("Det: %f\n", t.determinant());
}
