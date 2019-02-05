#include <vector>
#include <iostream>
#include "matrix.h"
#include "polynomial.h"
int main()
{
  Matrix<Poly<int>> A(3,3,0);
  A.set(1,1,1);
  A.set(1,2,1);
  A.set(2,3,1);
  A.set(3,1,1);
  Poly<int> z(1,0);
  z.set(1,1);
  int m=3;
  Poly<int> mPoly=3;
  int degree=10;
  //thing=A is 3x3 so we want to use a 3x3 identity matrix.
  Matrix<Poly<int>> I=Matrix<Poly<int>>::I(m);
  Matrix<Poly<int>> tmp=I-(A*z);
  Poly<int> F=Matrix<Poly<int>>::det(tmp);
  Poly<int> tmpPoly=z* F.prime();
  Poly<int> generatingFunction=mPoly-Poly<int>::TaylorSeries(tmpPoly,F,degree);
  std::cout<<generatingFunction;
  Poly<int> LHS=0;
  Matrix<Poly<int>> matrixPower=I;
  for(int i=0;i<=degree;i++)
  {
    Poly<int> x(i,0);
    x.set(i,1);
    LHS=LHS+Matrix<Poly<int>>::tr(matrixPower)*x;
    matrixPower=matrixPower*A;
  }
  std::cout<<LHS;

  return 0;
}
