#include <vector>
#include <iostream>
#include "matrix.h"
#include "polynomial.h"
//#include "gmpwrapper.h"
#include <fstream>
#include <gmpxx.h>

Matrix<mpf_class> readMatrix();

mpf_class cycleEmbeddings(int length, Matrix<mpf_class> A);

int main()
{
  //GMP mp?_class objects, used to prevent need for double implicit conversion (impossible)
  mpf_class one=1;
  mpf_class zero=0;

  Matrix<mpf_class> A=readMatrix();

  std::cout<<A; //redefined stream insertion for Matrix class
  for(int i=3;i<=5;i++)
  {
    mpf_class x=cycleEmbeddings(i, A);
    std::cout<<"i = "<<i<<": x = "<<x<<"\n";
  }
  return 0;
}
mpf_class cycleEmbeddings(int length, Matrix<mpf_class> A)  // returns the number of embeddings of a length-cycle into graph with incidence matrix A
{
  mpf_class output=0;
  mpf_class one=1;
  switch(length)  // handles the arbirtrary formulas for each length of cycle as per the Evaluation of Matrix Expressions... master project
  {
    case 3:
      {
        output=Matrix<mpf_class>::tr(A)*one/6;
        break;
      }
    case 4:
      {
        Matrix<mpf_class> A2=A*A;
        Matrix<mpf_class> A4=A2*A2;
        Matrix<mpf_class> inner=Matrix<mpf_class>::diag(A2);
        Matrix<mpf_class> h=A.hadamard(A);

        output=Matrix<mpf_class>::tr(A4)*one/8-Matrix<mpf_class>::tr(inner.hadamard(inner))*one/4+Matrix<mpf_class>::tr(h*h)*one/8;
        break;
      }
    case 5:
      {
      Matrix<mpf_class> A2=A*A;
      Matrix<mpf_class> A3=A2*A;
      Matrix<mpf_class> A5=A3*A2;
      output=Matrix<mpf_class>::tr(A5)*one/10-Matrix<mpf_class>::tr(Matrix<mpf_class>::diag(A2).hadamard(Matrix<mpf_class>::diag(A3)))*one/2+Matrix<mpf_class>::tr(A2.hadamard(A3))*one/2;
      break;
      }
    case 6:
      break;
    case 7:
      break;
    default:
      break;
  }
  return output;
}

Matrix<mpf_class> readMatrix()
{
  //std::ifstream file;
  //file.open("smallMatrix2");
  int r,c;
  //file>>r>>c;
  std::cin>>r>>c;
  mpf_class zero=0;
  Matrix<mpf_class> output(r,c,zero);
  for(int i=1;i<=r;i++)
  {
    for(int j=1;j<=c;j++)
    {
      int temp;
      //file>>temp;
      std::cin>>temp;
      mpf_class tempRat=temp;
      output.set(i,j,tempRat);
    }
  }
  return output;
}
