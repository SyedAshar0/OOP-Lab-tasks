#include<iostream>
#include<string>

using namespace std;
class Car
{
    protected:
    string model;
    double price;
    public:
    Car(string model,double price):model(model),price(price){};
     void setModel(string m)
    {
        model=m;
    }
    string getModel()
    {
        return model;
    }
    virtual void setPrice(double p)=0;
    double getPrice()
    {
        return price;
    }

};
class Color:public Car
{
    public:
    Color(string model,double price):Car(model,price){};
    void setPrice(double p)
    {
        price=p;
    }
};
class Company:public Car{
public:
Company(string model,double price):Car(model,price){};
 void setPrice(double p)
    {
        price=p;
    }
};
int main()
{
Color color("toyota",500);
Company company("nissan",1000);
color.setPrice(700);
company.setPrice(1500);
cout<<"color model :"<<color.getModel()<<" price:"<<color.getPrice()<<endl;
cout<<"company model :"<<company.getModel()<<" price:"<<company.getPrice()<<endl;
}