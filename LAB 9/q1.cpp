#include<iostream>
#include<string>

using namespace std;
class Shape
{
public:
virtual void getArea()=0;
};
class Rectangle: public Shape
{
public:
double s1,s2;
Rectangle(double s1,double s2):s1(s1),s2(s2){};
void getArea()override
{
   cout<<"Area:"<<s1*s2<<endl;
}
};
class Triangle: public Shape
{
    public:
    double base,height;
   Triangle(double base,double height):base(base),height(height){};
    void getArea()override
{
   cout<<"Area:"<<0.5*base*height<<endl;
}
};
int main()
{
Shape *ptr;
Rectangle rectangle(5.0,4.0);
ptr=&rectangle;
ptr->getArea();
Triangle triangle(5.0,6.0);
ptr=&triangle;
ptr->getArea();
}
