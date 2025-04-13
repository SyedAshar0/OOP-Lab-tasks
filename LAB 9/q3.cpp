#include<iostream>
#include<string>

using namespace std;
class Person
{
public:

virtual void getData()=0;
virtual void displayData()=0;
virtual void bonus()=0;
};
class admin:virtual public Person
{
    protected:
    string name;
    double salary;
public:

     void getData()override
     {
         cout<<"enter name:"<<endl;
         cin>>name;
         cout<<"enter salary:"<<endl;
         cin>>salary;
     }
     void displayData()override
     {
          cout<<"name:"<<name<<endl;
          cout<<"salary:"<<salary;
     }
     void bonus()override
     {
       cout<<"bonus:"<<salary*0.2<<endl;
     }

};
class account:virtual public Person{
    protected:
    string name;
    double salary;
public:

     void getData()override
     {
         cout<<"enter name:"<<endl;
         cin>>name;
         cout<<"enter salary:"<<endl;
         cin>>salary;
     }
     void displayData()override
     {
          cout<<"name:"<<name<<endl;
          cout<<"salary:"<<salary<<endl;
     }
     void bonus()override
     {
       cout<<"bonus:"<<salary*0.1<<endl;
     }
};
class Master: public admin, public account
{
    protected:
    string name;
    double salary;
public:

     void getData()override
     {
         cout<<"enter name:"<<endl;
         cin>>name;
         cout<<"enter salary:"<<endl;
         cin>>salary;
     }
     void displayData()override
     {
          cout<<"name:"<<name<<endl;
          cout<<"salary:"<<salary<<endl;
     }
     void bonus()override
     {
       cout<<" bonus:"<<salary*0.5<<endl;
     }

};
int main()
{
    Person *ptr;
    admin ad;
    Master m;
    account acc;
    ptr=&ad;
    cout<<"<-----admin----->"<<endl;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();
    ptr=&acc;
    cout<<"<-----Account----->"<<endl;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();
    ptr=&m;
    cout<<"<-----Master----->"<<endl;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();
     


}