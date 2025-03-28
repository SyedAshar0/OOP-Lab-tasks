#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
class fraction{
    private:
    int num;
    int denom;
    void reduce()
        {
            int div=gcd(num,denom);
            num=num/div;
            denom=denom/div;
            if(denom<0)
            {
                num=-num;
                denom=-denom;
            }
        }
    public:
    fraction(int numerator,int denominator):num(numerator),denom(denominator)
    {
       reduce();
    };
    fraction operator-(const fraction& other) {
        return fraction(num * other.denom -other.num * denom, denom * other.denom);
    }
    fraction operator+(const fraction& other) {
        return fraction(num * other.denom +other.num * denom, denom * other.denom);
    }
    fraction operator/(const fraction& other) {
        return fraction(num * other.denom, denom * other.num);
    }
    fraction operator*(const fraction& other) {
        return fraction(num * other.num, denom * other.denom);
    }
    bool operator==(const fraction& other) {
        return (num * other.denom== denom == other.num *denom);
    }
    bool operator!=(const fraction& other) {
        return !(*this==other);
    }
    bool operator<(const fraction& other) {
        return (num * other.denom < denom * other.num);
    }
    bool operator>(const fraction& other) {
        return (num * other.denom > denom * other.num);
    }
    bool operator<=(const fraction& other) {
        return (num * other.denom <= denom * other.num);
    }
    bool operator>=(const fraction& other) {
        return (num * other.denom <= denom * other.num);
    }
    friend ostream& operator<<(ostream& out,const fraction&other);
     friend istream& operator>>(istream& in, fraction&other);

};
ostream& operator<<(ostream& out,const fraction&other)
{
 out << other.num<<"/"<< other.denom ;
    return out;
}
istream& operator>>(istream& in,fraction&other)
{
  cout << "Enter numerator and denominator: ";
    in >> other.num >> other.denom;
    return in;
}
int main(){
    fraction f1(1,2);
    fraction f2(1,2);
    cout<<"F1:"<<f1<<endl;
    cout<<"F2:"<<f2<<endl;
    cout<<(f1 + f2)<<endl;
    
    
}