#include<iostream>
#include<string>
using namespace std;
class Date{
public:
int month;
int day;
int year;
void displayDate(){
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}    
};

int main(int argc,char*argv[]){
Date DateTest;
DateTest.month=stoi(argv[1]);
DateTest.day=stoi(argv[2]);
DateTest.year=stoi(argv[3]);
DateTest.displayDate();



return 0;

}
