#include<iostream>
#include<string>
using namespace std;
class Glass{
public:
int LiquidLevel=200;
public:
void Drink(int milliliters){
      cin>>milliliters;
      LiquidLevel-=milliliters;
}
void Refill(){
    if(LiquidLevel<100){
        LiquidLevel=200;
    }else if(LiquidLevel>=100){
        cout<<"sufficient level,no need of refill"<<endl;
    }
}
void Display(){
    cout<<"liquid level:"<<LiquidLevel<<endl;
}
};

int main(){
Glass glass;
int milliliters;
int choice;
do{
cout<<"1)drink"<<endl;
cout<<"2)refill"<<endl;
cout<<"3)display level"<<endl;
cout<<"4)exit"<<endl;
cin>>choice;
switch (choice)
{
case 1:
     glass.Drink(milliliters);
    break;
case 2:
    glass.Refill();
    break;
case 3:
    glass.Display();
    break;
case 4:
     cout<<"leaving..."<<endl;
     break;    
default:
cout<<"invalid input"<<endl;
    break;
}
}while(choice!=4);


return 0;



}
