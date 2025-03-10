#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Employee{
public:
string name;
int ID;   
virtual ~Employee(){};
};
class IOrderTaker{
    public:
    virtual void takeorder()=0;//pure virtual function
    virtual ~IOrderTaker(){};
};
class IOrderPreparer{
    public:
    virtual void PreparingOrder()=0;//pure virtual function
    virtual ~IOrderPreparer(){};
};
class IBiller{
    public:
    virtual void Billing()=0;//pure virtual function
    virtual ~IBiller(){};
};
class Waiter:public Employee,public IOrderTaker{
    public:
    void takeorder() override{
        cout<<"taking order"<<endl;
    }
};
class Manager:public Employee,public IOrderTaker,public IBiller{
    public:
    void takeorder() override{
        cout<<"taking order"<<endl;
    }
    void Billing() override{
        cout<<"creating Bill"<<endl;
    }
};
class Chef:public Employee,public IOrderPreparer{
    public:
    void PreparingOrder() override{
        cout<<"preparing order"<<endl;
    }
};
class Cashier:public Employee,public IBiller{
    public:
    void Billing() override{
        cout<<"creating Bill"<<endl;
    }
};
class Menu{
    public:
    double totalCosts;
    Menu():totalCosts(0){};

};
class FoodMenu:public Menu{
    public:
    double foodTax;
    FoodMenu(double tax):foodTax(tax){};
    void calculate(){
        totalCosts=totalCosts+(totalCosts*this->foodTax);
    }

};
class BeverageMenu:public Menu{
    public:
    double bevTax;
    BeverageMenu(double tax):bevTax(tax){};
    void calculate(){
        totalCosts=totalCosts+(totalCosts*this->bevTax);
    }
};
int main(){
    vector<IOrderPreparer*>orderPreparers;
    vector<IBiller*>billers;
    vector<IOrderTaker*>takers;
Manager * manager=new Manager();
Waiter * waiter=new Waiter();
Chef * chef=new Chef();
Cashier *cashier=new Cashier();
orderPreparers.push_back(chef);
billers.push_back(cashier);
takers.push_back(waiter);
takers.push_back(manager);
billers.push_back(manager);
FoodMenu foodMenu(0.5);
BeverageMenu beverageMenu(0.2);
foodMenu.totalCosts=150;
beverageMenu.totalCosts=200;
foodMenu.calculate();
beverageMenu.calculate();
cout<<"total food cost:" << foodMenu.totalCosts << endl;
cout<<"total beverage costs:" << beverageMenu.totalCosts << endl;
for(IOrderPreparer* preparer:orderPreparers){
    preparer->PreparingOrder();
}
for(IOrderTaker*taker:takers){
    taker->takeorder();
}
for(IBiller*biller:billers){
    biller->Billing();
}


delete waiter;
delete chef;
delete cashier;
delete manager;
return 0;
}