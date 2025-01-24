#include<iostream>
#include<iomanip>
using namespace std;
int main(int argc,char *argv[]){
    int id=stoi(argv[1]);
    string name=argv[2];
    int units_consumed=stoi(argv[3]);
    float amount;
    float surcharge;
    float bill=0;
    
    cout<<"customer id:"<<id<<endl;
    cout<<"customer name:"<<name<<endl;
    cout<<"units consumed:"<<units_consumed<<endl;
     cout<<fixed<<setprecision(2);
    if(units_consumed<=199){
       amount=units_consumed*16.20;
       cout<<"amount charges @16.20:"<<amount<<endl;
    }else if(units_consumed>=200 && units_consumed<300){
        amount=units_consumed*20.10;
         cout<<"amount charges @20.10:"<<amount<<endl;
    }else if(units_consumed>=300 && units_consumed<500){
        amount=units_consumed*27.10;
         cout<<"amount charges @27.10:"<<amount<<endl;
    }else if(units_consumed>=500){
        amount=units_consumed*35.90;
         cout<<"amount charges @35.90:"<<amount<<endl;
    }

    if(amount>18000){
      surcharge=amount*0.15;
      cout<<"surcharge amount:"<<surcharge<<endl;
    }
    bill=surcharge+amount;
    cout<<"net amount paid by customer:"<<bill<<endl;

    return 0;
}