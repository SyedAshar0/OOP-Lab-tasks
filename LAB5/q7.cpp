#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
    const string roll_no;
    Student(string r):roll_no(r){};
};
int main(int argc,char *argv[]){
  string x=argv[1];
  Student students(x);
  cout<<"roll no:"<<students.roll_no<<endl;


    return 0;
}