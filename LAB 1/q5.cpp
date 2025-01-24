#include<iostream>
#include<iomanip>
#include<string>

using namespace std;
int main(int argc,char*argv[]){
    string moviename=argv[1];
    float adult=stof(argv[2]);
    float child=stof(argv[3]);
    int tickets;
    int n1=stoi(argv[4]);//number of adult tickets sold
    int n2=stoi(argv[5]);//number of child tickets sold
    float amount;
    float percentagedonated=stof(argv[6]);
    float amountdonated;
    float netsale;
    cout<<fixed<<setprecision(2);
    amount=(n1*adult)+(n2*child);
    amountdonated=(amount * (percentagedonated/100));
    netsale=amount-amountdonated;
    tickets=n1+n2;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<left<<setw(50)<<"movie name:"<<right<<setw(25)<<moviename<<endl;
    cout<<left<<setw(50)<<"number of tickets sold:"<<right<<setw(25)<<tickets<<endl;
    cout<<left<<setw(50)<<"gross amount:"<<right<<setw(25)<<amount<<endl;
    cout<<left<<setw(50)<<"percentage of gross amount Donated:"<<right<<setw(25)<<percentagedonated<<endl;
    cout<<left<<setw(50)<<"amount donated:"<<right<<setw(25)<<amountdonated<<endl;
    cout<<left<<setw(50)<<"net sale:"<<right<<setw(25)<<netsale<<endl;
    return 0;
}