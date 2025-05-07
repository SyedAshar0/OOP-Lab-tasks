#include<iostream>
using namespace std;
template<typename T>class Shape{
    public:
 T side1,side2;
 Shape(T s1,T s2):side1(s1),side2(s2){};
 void multiply()
 {
    cout<<"result:"<<side1*side2<<endl;
 }

};
template<typename T>
//templated class inheritance
class Rectangle:public Shape<T>
{
    public:
 T dim1,dim2;
 Rectangle(T s1,T s2,T dim1,T dim2):Shape<T>(s1,s2),dim1(dim1),dim2(dim2){};
  void multiply()
  {
    cout<<"result:"<<dim1*dim2<<endl;

  }
};
int main()
{
    Shape<double>shaepe(1.0,9.8);
    Rectangle<double>recrec(2.0,3.0,5.0,4.2);
    shaepe.multiply();
    recrec.multiply();
 return 0;
}