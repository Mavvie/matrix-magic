#include "matrix.h"

Matrix::Matrix() {}
Matrix::~Matrix() {}

int mymod(int n, int b)
{
  while(n <= 0)
    n += b;
  while(n >= b)
    n -= b;
  return n;
}

Matrix Matrix::dot_product(Matrix B)
{
  Matrix result;
  for(int row=0; row<matrix.size(); row++)
  {
    vector<float> result_row;
    for(int col=0; col < B.matrix.at(0).size(); col++)
    {
      float sum = 0;
      for(int i=0; i<matrix.at(row).size(); i++)
      {
        sum += matrix.at(row).at(i) * B.matrix.at(i).at(col);
      }
      result_row.push_back(sum);
    }
    result.matrix.push_back(result_row);
  }
  return result;
}

Matrix Matrix::minors()
{
  Matrix minor;
  for(int row=0; row < matrix.size(); row++)
  {
    vector<float> r;
    minor.matrix.push_back(r);

    for(int col=0; col < matrix.at(row).size(); col++)
    {
      Matrix t;
      t.matrix = this->matrix;
      t.matrix.erase(t.matrix.begin() + row);
      for(int tr = 0; tr < t.matrix.size(); tr++)
      {
        t.matrix.at(tr).erase(t.matrix.at(tr).begin() + col);
      }
      minor.matrix.at(row).push_back(t.determinant());
    }
  }
  return minor;
}

Matrix Matrix::cofactors()
{
  Matrix ret;
  ret.matrix = this->matrix;
  for(int row=0; row < matrix.size(); row++)
  {
    for(int col=0; col < matrix.at(row).size(); col++)
    {
      bool odd_row = row % 2 == 1;
      bool odd_col = col % 2 == 1;
      if(odd_row || odd_col && !(odd_col && odd_row))
        ret.matrix.at(row).at(col) *= -1.0f;
    }
  }
  return ret;
}

Matrix Matrix::transpose()
{
  Matrix ret;
  ret.matrix = this->matrix;
  for(int row=0; row < matrix.size(); row++)
  {
    for(int col=0; col < matrix.at(row).size(); col++)
    {
      ret.matrix.at(col).at(row) = matrix.at(row).at(col);
    }
  }
  return ret;
}

Matrix Matrix::multiply(float scalar)
{
  Matrix ret;
  ret.matrix = this->matrix;
  for(int row=0; row < matrix.size(); row++)
  {
    for(int col=0; col < matrix.at(row).size(); col++)
    {
      ret.matrix.at(row).at(col) = matrix.at(row).at(col) * scalar;
    }
  }
  return ret;
}

Matrix Matrix::inverse()
{
  Matrix ret;
  if(determinant() == 0.0f)
    return ret;
  return minors().cofactors().transpose().multiply(1.0f/determinant());
}

float Matrix::determinant()
{
  float det = 0.0f;
  if(matrix.size() == 0)
    return 0.0f;
  if(matrix.at(0).size() == 0)
    return 0.0f;

  if(matrix.size() == 2 && matrix.at(0).size() == 2)
  {
    // 2x2 matrix is different (fml)
    return matrix.at(0).at(0)*matrix.at(1).at(1) - matrix.at(0).at(1)*matrix.at(1).at(0);
  }

  for(int start_col=0; start_col<matrix.at(0).size(); start_col++)
  {
    float term1 = 1.0f, term2 = 1.0f;
    for(int c = 0; c < matrix.size(); c++) {
      int row = c;
      int col = mymod(c + start_col, matrix.at(row).size());
      term1 *= matrix.at(row).at(col);
      // cout << "Row: " << row << "\tCol: " << col << "\tValue:" << matrix.at(row).at(col) << "\tNew term1:" << term1 << endl;
      row = c;
      col = mymod(start_col - c, matrix.at(row).size());
      term2 *= matrix.at(row).at(col);
      // cout << "Row: " << row << "\tCol: " << col << "\tValue:" << matrix.at(row).at(col) << "\tNew term2:" << term2 << endl;
    }
    det += term1 - term2;
  }
  return det;
}

void Matrix::inspect()
{
  cout << "Matrix:" << endl;
  for(int row = 0; row < matrix.size(); row++)
  {
    for(int col = 0; col < matrix.at(row).size(); col++)
    {
      cout << matrix.at(row).at(col) << " ";
    }
    cout << endl;
  }
}
