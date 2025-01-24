#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main(int argc,char *argv[]){
float w_kg=stoi(argv[1]);
float w_pound;
w_pound=(w_kg*2.2);
cout<<fixed<<setprecision(2);
cout<<"weight in kg is "<<w_kg<<endl;
cout<<"weight in pound is "<<w_pound<<endl;


    return 0;
}