#include<iostream>
using namespace std;
class Person
{
    protected:
    string EmployeeID;
    double income;
    public:
    Person(string EmployeeID):EmployeeID(EmployeeID){};
    string getData()
    {
        return  EmployeeID;
    }
    virtual void displayData(){
       cout<<"employee ID:"<<EmployeeID<<endl;
    }
    virtual double bonus()=0;
    virtual ~Person(){};
};
class Admin:public Person
{
    protected:
string name;
double income;
public:
Admin(string EmployeeID,string name,double income):Person(EmployeeID),name(name),income(income){};
string getName()
{
    return name;
}
double getIncome()
{
    return income;
}
double bonus() override
{
     return income*0.05;
}
void displayData() override
{
    cout<<"name:"<<getName()<<endl;
    Person::displayData();
    cout<<"income:"<<getIncome()<<endl;
    cout<<"bonus:"<<bonus()<<endl;
}
};
class Accounts:public Person
{
    protected:
string name;
double income;
public:
Accounts(string EmployeeID,string name,double income):Person(EmployeeID),name(name),income(income){};

string getName()
{
    return name;
}
double getIncome()
{
    return income;
}
double bonus()override
{
    return income*0.05;
}
void displayData() override
{
    cout<<"name:"<<getName()<<endl;
    Person::displayData();
    cout<<"income:"<<getIncome()<<endl;
    cout<<"bonus:"<<bonus()<<endl;
}
};
int main()
{
    Admin admin("1001","Syed",100);
    Accounts accounts("1002","Ashar",200);    
    cout<<"<-Admin->"<<endl;
    admin.displayData();
    cout<<"<--Accounts -->"<<endl;
    accounts.displayData();

 return 0;
}