#include<iostream>
#include<string>

using namespace std;
class Wallet
{
private:
double balance;
int dailyLimit;
const int limit;
public:
Wallet(double balance,int limit):balance(balance),limit(limit),dailyLimit(0){};
bool deposit(double b)
{
if(dailyLimit>=limit)
{
    cout<<"limit reached "<<endl;
    return false;
}
if(b<0)
{
    cout<<"invalid amount"<<endl;
    return false;
}
balance+=b;
dailyLimit++;
cout<<"amount deposited"<<endl;
return true;
}
bool withdraw(double b)
{
    if(dailyLimit>=limit)
    {
        cout<<"limit reached "<<endl;
        return false;
    }
    if(b<=0 || b>balance)
    {
        cout<<"invalid amount"<<endl;
        return false;
    }
    balance-=b;
    dailyLimit++;
    cout<<"amount withdrawn"<<endl;
    return true;
}
};
class User{
private:
string userID;
string name;
Wallet wallet;
public:
User(string userID,string name,double balance,int dailylimit):userID(userID),name(name),wallet(balance,dailylimit){};
void deposit(double b)
{
    wallet.deposit(b);
}
void withdraw(double b)
{
    wallet.withdraw(b);
}


};
int main()
{
 User user1("0582","Ashar",500,3);
 User user2("0101","Syed",400,2);
 user1.deposit(30);   
 user1.withdraw(20);  
 user1.withdraw(50);  
 user1.withdraw(10);  
 user2.deposit(20);
 user2.withdraw(100); 

}