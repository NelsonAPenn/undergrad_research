#include <algorithm>
#include <vector>
#include <iostream>
template <class T>
class Poly
{
  public:
    Poly<T>()
    {
      coefs.resize(0);
      coefs.resize(1);
      coefs[0]=0;
    }
    Poly<T>(const T& other)
    {
      coefs.resize(1);
      set(0,other);
    }
    Poly<T>(int other)
    {
      coefs.resize(1);
      set(0,(T)(other));
    }

    explicit Poly<T>(int degree, T initVal)
    {
      coefs.resize(0);
      coefs.resize(degree+1,initVal);
    }
    Poly<T> prime()
    {
      Poly<T> output(deg()-1,0);
      for(int i=1;i<coefs.size();i++)
      {
        output.set(i-1,coefs[i]*i);
      }
      return output;
    }
    void set(int pos, T coef)
    {
      coefs[pos]=coef;
    }
    T get(int pos)
    {
      return coefs[pos];
    }
    void removeTrailingZeros()
    {
      int j=0;
      for(auto i=coefs.rbegin();i!=coefs.rend() && (*i)==0;i++)
      {
        j++;
      }
      if(j==coefs.size())
        j--;
      coefs.resize(coefs.size()-j);
    }
    Poly<T> operator *(Poly<T> other)
    {
      Poly<T> output(deg()+other.deg(),0);
      for(int i=0;i<=deg();i++)
      {
        for(int j=0;j<=other.deg();j++)
        {
          output.set(i+j,output.get(i+j)+get(i)*other.get(j));
        }
      }
      output.removeTrailingZeros();
      return output;
    }
    Poly<T> operator /(Poly<T> other)
    {
      Poly<T> d=other;
      Poly<T> q;
      Poly<T> r=(*this);
      while(r.deg()!=-1 && r.deg()>=d.deg())
      {
        Poly<T> t(r.deg()-other.deg(),0);
        t.set(r.deg()-d.deg(),r.get(r.deg())/d.get(d.deg()));
        q=q+1;
        r=r-t*d;
      }
      return q;
    }
    Poly<T> operator +(Poly<T> other)
    {
      Poly<T> output(std::max(deg(),other.deg()),0);
      for(int i=0;i<=output.deg();i++)
      {
        if(i<=deg())
        {
          output.set(i,output.get(i)+get(i));
        }
        if(i<=other.deg())
        {
          output.set(i,output.get(i)+other.get(i));
        }
      }
      output.removeTrailingZeros();
      return output;
    }
    T operator ()(T x)
    {
      T output=0;
      for(auto i=coefs.rbegin();i!=coefs.rend();i++)
      {
        output*=x;
        output+=(*i);
      }
      return output;
    }
    Poly<T> operator -(Poly<T> other)
    {
      Poly<T> neg1=-1;
      return (*this)+(other*neg1);
    }
    int deg()
    {
      return coefs.size()-1;
    }
    static Poly<T> TaylorSeries(Poly<T> num, Poly<T> den, int deg)
    {
      T fact=1;
      Poly<T> output(deg,0);
      output.set(0,num(0)/den(0));
      for(int i=1;i<=deg;i++)
      {
        //take derivative
        num=(num.prime()*den)-(num*den.prime());
        den=den*den;
        //increase factorial
        fact*=i;
        //set value
        output.set(i,num(0)/den(0)/fact);
      }
      return output;
    }
  private:
    std::vector<T> coefs;
};
template <class T>
std::ostream & operator << (std::ostream & out, Poly<T> poly)
{
  out<<poly.get(0)<<"x^0";
  for(int r=1;r<=poly.deg();r++)
  {
    out<<" + "<<poly.get(r)<<"x^"<<r;
  }
  out<<'\n';
  return out;
}
