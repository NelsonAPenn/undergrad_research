#include <vector>
#include <iostream>
#include "matrix.h"
#include "polynomial.h"
//#include "gmpwrapper.h"
#include <gmpxx.h>
int main()
{
  mpq_class q(2,4);
  q.canonicalize();
 
  std::cout<<q.get_num()<<"/"<<q.get_den();
  return 0;
}
