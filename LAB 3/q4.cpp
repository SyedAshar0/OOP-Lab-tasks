#include<iostream>
#include<string>
using namespace std;
class Employee{
public:
string first_name;
string last_name;
double monthly_salary;
 void check(){
    if(monthly_salary<0){
        monthly_salary=0.0;
    }
 }
};

int main(int argc,char*argv[]){
Employee EmployeeTest1;
Employee EmployeeTest2;
EmployeeTest1.first_name=argv[1];
EmployeeTest1.last_name=argv[2];
EmployeeTest1.monthly_salary=stoi(argv[3]);
EmployeeTest1.check();
EmployeeTest2.first_name=argv[4];
EmployeeTest2.last_name=argv[5];
EmployeeTest2.monthly_salary=stoi(argv[6]);
EmployeeTest2.check();
cout<<"without raise"<<endl;
cout<<"name:"<<EmployeeTest1.first_name<<EmployeeTest1.last_name<<endl;
cout<<(EmployeeTest1.monthly_salary*12)<<endl;
cout<<"name:"<<EmployeeTest2.first_name<<EmployeeTest2.last_name<<endl;
cout<<(EmployeeTest2.monthly_salary*12)<<endl;
cout<<"with raise"<<endl;
EmployeeTest1.monthly_salary=EmployeeTest1.monthly_salary+(EmployeeTest1.monthly_salary*0.1);
EmployeeTest2.monthly_salary=EmployeeTest2.monthly_salary+(EmployeeTest2.monthly_salary*0.1);
cout<<"name:"<<EmployeeTest1.first_name<<EmployeeTest1.last_name<<endl;
cout<<(EmployeeTest1.monthly_salary*12)<<endl;
cout<<"name:"<<EmployeeTest2.first_name<<EmployeeTest2.last_name<<endl;
cout<<(EmployeeTest2.monthly_salary*12)<<endl;


return 0;







}
