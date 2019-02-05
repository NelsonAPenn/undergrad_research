#include <vector>
#include <iostream>
#include "matrix.h"
#include "polynomial.h"
int main()
{
  //small example
  Matrix<Poly<long>> A(3,3,0);
  A.set(1,1,1);
  A.set(1,2,1);
  A.set(2,3,1);
  A.set(3,1,1);
  Poly<long> z(1,0);
  z.set(1,1);
  int m=3;
  Poly<long> mPoly=3;
  int degree=10;
  //thing=A is 3x3 so we want to use a 3x3 identity matrix.
  Matrix<Poly<long>> I=Matrix<Poly<long>>::I(m);
  Matrix<Poly<long>> tmp=I-(A*z);
  Poly<long> F=Matrix<Poly<long>>::det(tmp);
  Poly<long> tmpPoly=z* F.prime();
  Poly<long> generatingFunction=mPoly-Poly<long>::TaylorSeries(tmpPoly,F,degree);
  Poly<long> LHS=0;
  Matrix<Poly<long>> matrixPower=I;
  for(int i=0;i<=degree;i++)
  {
    Poly<long> x(i,0);
    x.set(i,1);
    LHS=LHS+Matrix<Poly<long>>::tr(matrixPower)*x;
    matrixPower=matrixPower*A;
  }
  std::cout<<"Small example: \n";
  std::cout<<"LHS: "<<LHS;
  std::cout<<"RHS: "<<generatingFunction;

  //Large example, all 1`s except for diagonal
  degree=5;
  m=100;
  mPoly=m;
  I=Matrix<Poly<long>>::I(m);
  A=Matrix<Poly<long>>(m,m,1);
  A=A-I;
  LHS=0;
  matrixPower=I;
  for(int i=0;i<=degree;i++)
  {
    Poly<long> x(i,0);
    x.set(i,1);
    LHS=LHS+Matrix<Poly<long>>::tr(matrixPower)*x;
    matrixPower=matrixPower*A;
  }
  std::cout<<"Large example: \n";
  std::cout<<"LHS: "<<LHS;
  
  F=Matrix<Poly<long>>::det(I-(A*z));
  generatingFunction=mPoly-Poly<long>::TaylorSeries(z*F.prime(),F,degree);
  std::cout<<"RHS: "<<generatingFunction;
  
  return 0;
}
