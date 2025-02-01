#include<iostream>

using namespace std;
struct Employee{
    int employee_id;
    string name;
    float salary;
};
struct Organisation{
    string organisation_name;
    string organisation_number;
    Employee emp;
    int size;
};


int main(int argc,char*argv[]){
    Organisation org;
    org.size=stoi(argv[1]);
    org.organisation_name=argv[2];
    org.organisation_number=argv[3];
    org.emp.employee_id=stoi(argv[4]);
    org.emp.name=argv[5];
    org.emp.salary=stof(argv[6]);

cout<<"size of structure organistaion:"<<org.size<<endl;
cout<<"organisation name:"<<org.organisation_name<<endl;
cout<<"organisation number:"<<org.organisation_number<<endl;
cout<<"employee id:"<<org.emp.employee_id<<endl;
cout<<"employee name:"<<org.emp.name<<endl;
cout<<"employee salary:"<<org.emp.salary<<endl;

    return 0;
}