#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Polynomial
{
    private:
    vector<int>Coefficients;
    public:
    friend class PolynomialUtils;
    Polynomial(){};
    Polynomial(vector<int> coeff):Coefficients(coeff){};
    Polynomial operator +(const Polynomial&other)
    {
       int loop_size=max(Coefficients.size(),other.Coefficients.size());
       vector<int>Result(loop_size,0);
       for(int i=0;i<loop_size;i++)
       {
        if(i<Coefficients.size())
        {
            Result[i]+=Coefficients[i];
        }
        if(i<other.Coefficients.size())
        {
            Result[i]+=other.Coefficients[i];
        }
       }   
       return Polynomial(Result);
    }
    Polynomial operator -(const Polynomial&other)
    {
       int loop_size=max(Coefficients.size(),other.Coefficients.size());
       vector<int>Result(loop_size,0);
       for(int i=0;i<loop_size;i++)
       {
        if(i<Coefficients.size())
        {
            Result[i]=Coefficients[i];
        }
        if(i<other.Coefficients.size())
        {
            Result[i]-=other.Coefficients[i];
        }
       }   
       return Polynomial(Result);
    }
    Polynomial operator *(const Polynomial&other)
    {
       int loop_size=Coefficients.size()+other.Coefficients.size() -1;
       vector<int>Result(loop_size,0);
       for(int i=0;i<Coefficients.size();i++)
       {
        for(int j=0;j<other.Coefficients.size();j++)
        {
            Result[i+j]+=Coefficients[i]*other.Coefficients[j];
        }
       }   
       return Polynomial(Result);
    }
    friend ostream& operator<<(ostream& out, const Polynomial& poly)
    {
        bool firstTerm=true;
        for (int i=0; i<poly.Coefficients.size(); i++)
        {
            int coeff=poly.Coefficients[i];
            if(coeff!=0)
            {
                if(!firstTerm)
                {
                    out<<(coeff>0?" + ":" - ");
                }
                else if(coeff<0)
                {
                    out<< "-";
                }
                int abs_coeff = abs(coeff);
                if(abs_coeff!= 1||i==poly.Coefficients.size()-1)
                {
                    out<<abs_coeff;
                }
                int exponent=poly.Coefficients.size()-i-1;
                if(exponent>0)
                {
                    out<< "x";
                    if(exponent>1)
                    {
                        out<< "^" << exponent;
                    }
                }
                firstTerm=false;
            }
        }
        return out;
    }
};
class PolynomialUtils
{
    public:
    int evaluate(const Polynomial &p,int x)
    {
        int result=0;
        for(int i=0;i<p.Coefficients.size();i++)
        {
            result+=p.Coefficients[i]*pow(x,p.Coefficients.size()-i-1);
        }
        return result;
    }
    Polynomial derivative(const Polynomial&p)
    {
          vector<int>result;
          for(int i=0;i<p.Coefficients.size()-1;i++)
          {
            result.push_back(p.Coefficients[i]* (p.Coefficients.size()-i-1));
          }
          return Polynomial(result);
    }

};
int main()
{
    Polynomial poly1({5,4,3,-2,1});
    Polynomial poly2({1,-4,3});

    cout<<"Polynomial 1:"<<poly1<<endl;
    cout<<"Polynomial 2:"<<poly2<<endl;
    
    Polynomial Sum=poly1+poly2;
    cout<<"SUM:"<<Sum<<endl;
    Polynomial Sub=poly1-poly2;
    cout<<"Subtraction product:"<<Sub<<endl;
    Polynomial Multiplication=poly1*poly2;
    cout<<"multiplication:"<<Multiplication<<endl;

    PolynomialUtils obj;
    int evaluatee=obj.evaluate(poly1,5);
    int evaluateee=obj.evaluate(poly2,2);
    cout<<"evaluation of polynomial 1:"<<evaluatee<<endl;
    cout<<"evaluation of polynomial 2:"<<evaluateee<<endl;

    Polynomial poly1dev=obj.derivative(poly1);
    Polynomial poly2dev=obj.derivative(poly2);
    cout<<"derivative of polynomial 1:"<<poly1dev<<endl;
    cout<<"derivative of polynomial 2:"<<poly2dev<<endl;
 return 0;
}