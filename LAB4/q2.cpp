#include<iostream>
#include<string>
using namespace std;
class Account{
    public:
     double accountBalance;
     Account(){
        accountBalance=0;
     }
     void credit(double amount){ 
          if(accountBalance>=0){
            accountBalance+=amount;
          }else{
            cout<<"dont have sufficient balance to credit"<<endl;
          }
     }
     void debits(double amount){
        if(accountBalance>=0){
            accountBalance-=amount;
          }else{
            cout<<"dont have sufficient balance to credit"<<endl;
          }
     }
     double getBalance(){
        return accountBalance;
     }
};
int main(int argc,char *argv[]){
Account Bank;
double amount1=stod(argv[1]);
double amount2=stod(argv[2]);
cout<<"current balance:"<<Bank.getBalance()<<endl;
cout<<"adding amount..."<<endl;
Bank.credit(amount1);
cout<<"current balance:"<<Bank.getBalance()<<endl;
cout<<"withdrawing amount"<<endl;
Bank.debits(amount2);
cout<<"current balance:"<<Bank.getBalance()<<endl;




}