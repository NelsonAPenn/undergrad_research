#include <cstddef>
#include <climits>
#include <cstdlib>
#include <vector>
#include <iostream>
template <class T>
class Matrix{
  public:
    static Matrix<T> I(int n)
    {
      T zero=0;
      Matrix<T> identity(n,n,zero);
      T one=1;
      for(int i=1;i<=n;i++)
      {
        identity.set(i,i,one);
      }
      return identity;
    }
    static T det(Matrix<T> matrix)
    {
      if(matrix.dim(0)!=matrix.dim(1))
        return NULL;
      int n=matrix.dim(0);
      if(n==1)
        return matrix.get(1,1);
      T sum=0;
      for(int i=1;i<=n;i++)
      {
        if(i%2==0)
        {
          sum=sum - matrix.get(1,i)*det(matrix.crossOut(1,i));
        }
        else
        {
          sum=sum+ matrix.get(1,i)*det(matrix.crossOut(1,i));
        }
      }
      return sum;
    }
    static T tr(Matrix<T> matrix)
    {
      if(matrix.dim(0)!=matrix.dim(1))
      {
        return NULL;
      }
      int n=matrix.dim(0);
      T sum=0;
      for(int i=1;i<=n;i++)
      {
        sum=sum+matrix.get(i,i);
      }
      return sum;
    }
    static Matrix<T> diag(Matrix<T> matrix)
    {
      if(matrix.dim(0)!=matrix.dim(1))
        std::cout<<"error";
      int n=matrix.dim(0);
      T zero=0;
      Matrix<T> output(n,n,zero);
      for(int i=1;i<=n;i++)
      {
        output.set(i,i,matrix.get(i,i));
      }
      return output;
    }
    Matrix<T>(int r1, int c1, T initVal)
    {
      this->r=r1;
      this->c=c1;
      while(r1--)
      {
        std::vector<T> tmp(c1,initVal);
        values.push_back(tmp);
      }
    }
    
    Matrix<T> crossOut(int row, int col)
    {
      row--;col--;
      T nothing=0;
      Matrix<T> output(this->r-1,this->c-1,nothing);
      for(int i=0;i<r;i++)
      {
        for(int j=0;j<c;j++)
        {
          if(i!=row && j!=col)
          {
            int in1=i;
            int in2=j;
            if(i>row)
            {
              in1--;
            }
            if(j>col)
            {
              in2--;
            }
            output.set(in1+1,in2+1,values[i][j]);
          }
        }
      }
      return output;

    }
    T get(int row, int col)
    {
      return values[row-1][col-1];
    }
    void set(int row, int col, T val)
    {
      values[row-1][col-1]=val;
    }
    void resize(int row, int col)
    {
      values.resize(row);
      for(auto i:values)
        i.resize(col);
      r=row;
      c=col;
    }
    int dim(int desiredDim)
    {
      if(desiredDim==0)
        return r;
      return c;
    }
    Matrix<T> operator*(Matrix<T> other)
    {
      if(dim(1)!=other.dim(0))
      {
        T nothing=0;
        return Matrix(0,0,nothing);
      }
      Matrix<T> output(this->r,other.dim(1),0);
      for(int i=1;i<=output.dim(0);i++)
      {
        for(int j=1;j<=output.dim(1);j++)
        {
          T sum=0;
          for(int k=1;k<=this->c;k++)
          {
            sum=sum+(get(i,k)*other.get(k,j));
          }
          output.set(i,j,sum);
        }
      }
      return output;
    }
    Matrix<T> operator*(T scalar)
    {
      T zero=0;
      Matrix<T> output(this->r,this->c,zero);
      for(int i=0;i<this->r;i++)
      {
        for(int j=0;j<this->c;j++)
        {
          output.set(i+1,j+1,scalar*get(i+1,j+1));
        }
      }
      return output;
    }
    Matrix<T> operator+(Matrix<T> other)
    {
      T zero=0;
      Matrix<T> output(this->r,this->c,zero);
      for(int i=0;i<this->r;i++)
      {
        for(int j=0;j<this->c;j++)
        {
          output.set(i+1,j+1,values[i][j]+other.get(i+1,j+1));
        }
      }
      return output;
    }
    Matrix<T> operator-(Matrix<T> other)
    {
      T inv=-1;
      return (*this)+(other*inv);
    }
    Matrix<T> hadamard(Matrix<T> other)
    {
      if(dim(0)!=other.dim(0) || dim(1)!=other.dim(1))
      {
        T nothing=0;
        return Matrix(0,0,nothing);
      }
      T nothing=0;
      Matrix<T> output(dim(0),dim(1),nothing);
      for(int i=1;i<=dim(0);i++)
      {
        for(int j=1;j<=dim(1);j++)
        {
          output.set(i,j,get(i,j)*other.get(i,j));
        }
      }
      return output;
    }
  private:
    std::vector<std::vector<T>> values;
    int r;
    int c;
};
  template <class T>
std::ostream & operator << (std::ostream & out, Matrix<T> matrix)
{
  for(int r=1;r<=matrix.dim(0);r++)
  {
    out<<"[ ";
    for(int c=1;c<=matrix.dim(1);c++)
    {
      out<<(matrix.get(r,c))<<" ";
    }
    out<<"]\n";
  }
  return out;
}
