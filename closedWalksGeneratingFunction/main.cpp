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
  //thing=A is 3x3 so we want to use a 3x3 identity matrix.
  Matrix<Poly<int>> I=Matrix<Poly<int>>::I(m);
  Matrix<Poly<int>> tmp=I-(A*z);
  Poly<int> F=Matrix<Poly<int>>::det(tmp);
  Poly<int> tmpPoly=z* F.prime();
  Poly<int> generatingFunction=mPoly-Poly<int>::TaylorSeries(tmpPoly,F,10);
  std::cout<<generatingFunction;

  return 0;
}
