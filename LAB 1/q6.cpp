#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main(int argc,char*argv[]){
string name=argv[1];
float score[5];
float total=0;
float avg;
int j=2;//works as a counter to increment in a loop since name takes gap as well 
for(int i=0;i<5;i++){
    score[i]=stof(argv[j]);//each string is converted to float as well using this
j++;
}
for(int i=0;i<5;i++){
    total=total+score[i];
}
avg=total/5;
cout<<fixed<<setprecision(2);
cout<<"output"<<endl;
cout<<name<<endl;
for(int i=0;i<5;i++){
    cout<<score[i]<<endl;
}
cout<<"average test score is:"<<avg<<endl;
}