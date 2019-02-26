#include <vector>
#include <iostream>
#include "matrix.h"
#include "polynomial.h"
//#include "gmpwrapper.h"
#include <gmpxx.h>
int main()
{
  int m=0;
  std::cout<<"Enter size of matrix: \n";
  std::cin>>m;
  int degree=0;
  std::cout<<"Enter desired degree of polynomial:\n";
  std::cin>>degree;
  //Large example, all 1`s except for diagonal
  Poly<mpz_class> mPoly=(mpz_class)(m);
  Matrix<Poly<mpz_class>> I=Matrix<Poly<mpz_class>>::I(m);
  Matrix<Poly<mpz_class>> A=Matrix<Poly<mpz_class>>(m,m,(mpz_class)(1));
  A=A-I;
  Poly<mpz_class> LHS=(mpz_class)(0);
  Matrix<Poly<mpz_class>> matrixPower=I;
  for(int i=0;i<=degree;i++)
  {
    Poly<mpz_class> x(i,(mpz_class)(0));
    x.set(i,(mpz_class)(1));
    LHS=LHS+Matrix<Poly<mpz_class>>::tr(matrixPower)*x;
    matrixPower=matrixPower*A;
  }
  std::cout<<"Large example: \n";
  std::cout<<"LHS: "<<LHS;
  Poly<mpz_class> z(1,(mpz_class)(0));
  z.set(1,(mpz_class)(1));
  
  Poly<mpz_class> F=Matrix<Poly<mpz_class>>::det(I-(A*z));
  Poly<mpz_class> generatingFunction=mPoly-Poly<mpz_class>::TaylorSeries(z*F.prime(),F,degree);
  std::cout<<"RHS: "<<generatingFunction;
  
  return 0;
}
