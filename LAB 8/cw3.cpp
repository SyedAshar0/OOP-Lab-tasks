#include<iostream>
#include<vector>
#include<string>
using namespace std;
class BigInteger{
private:
vector<int>digits;
bool isNegative;

void trim(){
while(digits.size()>1&&digits.back()==0){digits.pop_back();}
if(digits.empty()){digits.push_back(0);isNegative=false;}
}

static bool absCompare(const BigInteger&a,const BigInteger&b){
if(a.digits.size()!=b.digits.size()){return a.digits.size()<b.digits.size();}
for(int i=a.digits.size()-1;i>=0;--i){if(a.digits[i]!=b.digits[i]){return a.digits[i]<b.digits[i];}}
return false;
}

static BigInteger subtractAbs(const BigInteger&a,const BigInteger&b){
BigInteger result;
result.digits.clear();
int borrow=0;
for(size_t i=0;i<a.digits.size();++i){
int diff=a.digits[i]-borrow;
if(i<b.digits.size()){diff-=b.digits[i];}
if(diff<0){diff+=10;borrow=1;}else{borrow=0;}
result.digits.push_back(diff);
}
result.trim();
return result;
}

public:
BigInteger(const string&num="0"){
isNegative=(num[0]=='-');
digits.clear();
for(int i=num.length()-1;i>=(isNegative?1:0);--i){digits.push_back(num[i]-'0');}
trim();
}

BigInteger operator+(const BigInteger&other)const{
if(!isNegative&&!other.isNegative){
BigInteger result;
result.digits.clear();
int carry=0;
size_t maxSize=digits.size()>other.digits.size()?digits.size():other.digits.size();
for(size_t i=0;i<maxSize||carry;++i){
if(i>=result.digits.size())result.digits.push_back(0);
int sum=result.digits[i]+carry;
if(i<digits.size())sum+=digits[i];
if(i<other.digits.size())sum+=other.digits[i];
carry=sum/10;
result.digits[i]=sum%10;
}
result.trim();
return result;
}else if(isNegative&&!other.isNegative){
BigInteger temp=*this;
temp.isNegative=false;
return other-temp;
}else if(!isNegative&&other.isNegative){
BigInteger temp=other;
temp.isNegative=false;
return *this-temp;
}else{
BigInteger temp=*this;
temp.isNegative=false;
BigInteger result=temp+other;
result.isNegative=true;
return result;
}
}

BigInteger operator-(const BigInteger&other)const{
if(!isNegative&&!other.isNegative){
if(absCompare(*this,other)){
BigInteger result=subtractAbs(other,*this);
result.isNegative=true;
return result;
}
BigInteger result=subtractAbs(*this,other);
return result;
}else if(isNegative&&!other.isNegative){
BigInteger temp=*this;
temp.isNegative=false;
BigInteger result=temp+other;
result.isNegative=true;
return result;
}else if(!isNegative&&other.isNegative){
BigInteger temp=other;
temp.isNegative=false;
return *this+temp;
}else{
BigInteger temp1=*this;
BigInteger temp2=other;
temp1.isNegative=false;
temp2.isNegative=false;
return temp2-temp1;
}
}

bool operator==(const BigInteger&other)const{
if(isNegative!=other.isNegative||digits.size()!=other.digits.size()){return false;}
for(size_t i=0;i<digits.size();++i){if(digits[i]!=other.digits[i])return false;}
return true;
}

bool operator!=(const BigInteger&other)const{
return!(*this==other);
}

bool operator<(const BigInteger&other)const{
if(isNegative!=other.isNegative)return isNegative;
if(isNegative)return absCompare(other,*this);
return absCompare(*this,other);
}

bool operator>(const BigInteger&other)const{
return other<*this;
}

bool operator<=(const BigInteger&other)const{
return!(*this>other);
}

bool operator>=(const BigInteger&other)const{
return!(*this<other);
}

friend ostream&operator<<(ostream&os,const BigInteger&num){
if(num.isNegative&&(num.digits.size()>1||num.digits[0]!=0)){os<<'-';}
for(int i=num.digits.size()-1;i>=0;--i){os<<num.digits[i];}
return os;
}

friend istream&operator>>(std::istream&is,BigInteger&num){
string input;
is>>input;
num=BigInteger(input);
return is;
}
};
int main(){
BigInteger a("123456789");
BigInteger b("-987654321");
cout<<"a="<<a<<std::endl;
cout<<"b="<<b<<std::endl;
cout<<"a+b="<<(a+b)<<std::endl;
cout<<"a-b="<<(a-b)<<std::endl;
cout<<"a<b:"<<(a<b)<<std::endl;
cout<<"a>b:"<<(a>b)<<std::endl;
BigInteger c;
cout<<"Enter a number:";
cin>>c;
cout<<"You entered:"<<c<<std::endl;
return 0;
}