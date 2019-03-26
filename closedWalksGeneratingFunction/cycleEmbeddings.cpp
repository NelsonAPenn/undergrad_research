#include <vector>
#include <iostream>
#include "matrix.h"
#include "polynomial.h"
//#include "gmpwrapper.h"
#include <fstream>
#include <gmpxx.h>
Matrix<mpq_class> readMatrix();
mpq_class cycleEmbeddings(int length, Matrix<mpq_class> A);
int main()
{
  mpq_class one=1;
  mpq_class zero=0;

  Matrix<mpq_class> A=readMatrix();
  std::cout<<A;
  for(int i=3;i<=5;i++)
  {
    mpq_class x=cycleEmbeddings(i, A);
    std::cout<<"i = "<<i<<": x = "<<x<<"\n";
  }
  return 0;
}
mpq_class cycleEmbeddings(int length, Matrix<mpq_class> A)
{
  mpq_class output=0;
  mpq_class one=1;
  switch(length)
  {
    case 3:
      {
        output=Matrix<mpq_class>::tr(A)*one/6;
        break;
      }
    case 4:
      {
        Matrix<mpq_class> inner=Matrix<mpq_class>::diag(A*A);
        Matrix<mpq_class> h=A.hadamard(A);
        output=Matrix<mpq_class>::tr(A*A*A*A)*one/8-Matrix<mpq_class>::tr(inner.hadamard(inner))*one/4+Matrix<mpq_class>::tr(A.hadamard(A)*A.hadamard(A))*one/8;
        break;
      }
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    default:
      break;
  }
  return output;
}

Matrix<mpq_class> readMatrix()
{
  std::ifstream file;
  file.open("inMatrix");
  int r,c;
  file>>r>>c;
  mpq_class zero=0;
  Matrix<mpq_class> output(r,c,zero);
  for(int i=1;i<=r;i++)
  {
    for(int j=1;j<=c;j++)
    {
      int temp;
      file>>temp;
      mpq_class tempRat=temp;
      output.set(i,j,tempRat);
    }
  }
  return output;
}
