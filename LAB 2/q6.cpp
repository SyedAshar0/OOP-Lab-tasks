#include<iostream>
#include<vector>
using namespace std;

struct Inner{
    string subject;
};
struct Outer{
    int ID;
    Inner subjects[5];
};

void add(vector<Outer>&array,int argc,char *argv[]){
    int w=1;//ive use a w variable which acts as a index starting from 1 since argv[0 would certainly be the name of the program and also to avoid the stoi error of invalid arguments. 
for(int i=0;i<array.size();i++){
    array[i].ID=stoi(argv[w]);
    w++;
    for(int j=0;j<5;j++){
    array[i].subjects[j].subject=(argv[w]);
    w++;
}
}
}
void display(vector<Outer>&array){
    for(int i=0;i<array.size();i++){
        cout<<"ID:"<<array[i].ID<<endl;
        for(int j=0;j<5;j++){
        cout<<"subject:"<<j+1<<":"<<array[i].subjects[j].subject<<endl;
    }
    }
}
int main(int argc,char*argv[]){
    //doing this to make finite numbe rof outer structure depending on the arguments presented hence the argc-1.
    int n=(argc-1)/6;//argc-1 to accomodate command line arguments and since each outer has a single id and consists of 5 inner t=so ttal of 6 arguments
vector<Outer>array(n);
add(array,argc,argv);
display(array);








    return 0;
}