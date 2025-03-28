#include<iostream>
#include<string>
using namespace std;
class counter{
    private:
    int value;
    public:
    counter(int value=0):value(value){};
//prefix
    counter& operator--()
    {
        value=value*4;
        return *this;
    }
 //postfix
    counter operator--(int)
    {
        //i used a temp object name for counter class with value/4 initialized because otherwise the postfix and prefix were not working independently i.e->one of them was returning the original value without and operation performed on it
        //so 8/4=>2 and this temp object is returned as to prevent any unnecessary changes.
        counter temp(value/4);
        return temp;
    }
    void display()const
    {
      cout<<"value:"<<value<<endl;;
    }
};

int main()
{
    counter c(8);
    cout<<"<-----postfix----->"<<endl;
    counter temp=c--;
    temp.display();
    cout<<"<-----prefix----->"<<endl;
    --c;
    c.display();
    
 return 0;
}