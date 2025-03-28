#include<iostream>
using namespace std;
class Shape
{
    private:
    double length;
    double width;
    public:
    Shape(double length,double width):length(length),width(width){};
    double Area() 
    {
        return length*width;;
    }
    friend  Shape operator+(const Shape& shape1,const Shape& shape2);
};
Shape operator+(const Shape& shape1,const Shape& shape2){//const to ensure that the data is not modified within scope of operator
    //usage of &->used for pass by reference to prevent copying since without & the compiler would crete a new copy inside the function and with pass by reference there is no extra copies made
 return Shape(shape1.length+shape2.length,shape1.width+shape2.width);//returning a new object with new dimensions which can be used on new objects area.
}
int main()
{
    Shape shape1(4,5);
    Shape shape2(2,3);
    Shape shape3=shape1 + shape2;
    cout<<"Area of new shape is:"<<shape3.Area()<<endl;
 return 0;
}

//passing by value results in changes in copy of object meanwhile original object ramins unaffected.