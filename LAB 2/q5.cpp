#include<iostream>
#include<string>
using namespace std;
struct Employee{
    int ID;
    string name;
};
void add(Employee *emp,int argc,char*argv[]){
    int w=1;//a single w index needs to be used to have argument for a single employee having id and name and thus we need to incremment w after each employee by 2 to skip to next employee effectively.
    for(int i=0;i<(argc-1)/2;i++){///2 will allow a single index to occupy w such that the arguments area cceptable as a pair
         emp[i].ID=stoi(argv[w]);
         emp[i].name=argv[w+1];
         w=w+2;
    }
}
void display(Employee*emp,int argc){
    for(int i=0;i<(argc-1)/2;i++){
        cout<<"ID of slot:"<<i+1<<":"<<emp[i].ID<<endl;
        cout<<"name of slot:"<<i+1<<":"<<emp[i].name<<endl;
    }
}
void sorting1(Employee*emp,int argc){
    for(int i=0;i<(argc-1)/2;i++){
        for(int j=i+1;j<(argc-1)/2;j++){
            if(emp[i].ID>emp[j].ID){
                 Employee temp=emp[i];
                emp[i]=emp[j];
                emp[j]=temp;

            }
        }
    }
}
void sorting2(Employee*emp,int argc){
    for(int i=0;i<(argc-1)/2;i++){
        for(int j=i+1;j<(argc-1)/2;j++){
            if(emp[i].name[0]>emp[j].name[0]){
                Employee temp=emp[i];
                emp[i]=emp[j];
                emp[j]=temp;
            }
        }
    }
}
int main(int argc,char*argv[]){
   Employee *emp=new Employee[argc-1];//allocated memory for n structures depending on number of arguments 
   add(emp,argc,argv);
   display(emp,argc);
   sorting1(emp,argc);
   cout<<"<---structure sorted via ID--->"<<endl;
   display(emp,argc);
   cout<<"<---structure sorted via first name--->"<<endl;
   sorting2(emp,argc);
   display(emp,argc);










    return 0;
}