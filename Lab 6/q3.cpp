#include<iostream>
#include<string>
using namespace std;
class Student{
   int id;
   string name;
   public:
   void setname(string x){
    name=x;
   }
   void setid(int ID){
    id=ID;
   }
   void getstudentdetails(){
      cout<<"name:"<<name<<endl;
      cout<<"id:"<<id<<endl;
   }
};
class Marks:public Student{
    protected:
    int marks_oop,marks_pf,marks_ds,marks_db;
    public:
    void marks(int w,int x,int y,int z){
        marks_oop=w;
        marks_pf=x;
        marks_ds=y;
        marks_db=z;
    }
    void getmarks(){
        cout<<"<-----Marks----->"<<endl;
       cout<<"oop:"<<marks_oop<<endl;
       cout<<"pf:"<<marks_pf<<endl;
       cout<<"db:"<<marks_db<<endl;
       cout<<"ds:"<<marks_ds<<endl;
    }
    
};
class Result:public Marks{
    protected:
    int total_marks;
    double avg_marks;
    public:
    void calc(){
        total_marks=(marks_oop+marks_ds+marks_pf+marks_db);
        avg_marks=total_marks/4;
    }
    void display(){
      Student::getstudentdetails();
      Marks::getmarks();
      cout<<"<-----Result----->"<<endl;
      cout<<"total:"<<total_marks<<endl;
      cout<<"average:"<<avg_marks<<endl;
    
    }
};
int main(){
 Result result;
 result.setname("Syed Ashar");
 result.setid(909);
 result.marks(70,80,90,99);
 result.calc();
 result.display();

}