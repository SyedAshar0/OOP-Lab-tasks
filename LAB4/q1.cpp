#include<iostream>
#include<string>
#define PI 3.142
using namespace std;
class Circle{
    public:
    double radius;
    Circle(double radius){
        this->radius=radius;
    }
    double getArea(){
        return PI*(radius*radius);
    }
    double getPerimeter(){
        return 2*PI*radius;
    }
};
int main(int argc,char *argv[]){
    Circle circle=Circle(stoi(argv[1]));
    cout<<"area:"<<circle.getArea()<<endl;
    cout<<"perimeter:"<<circle.getPerimeter()<<endl;
    return 0;


}