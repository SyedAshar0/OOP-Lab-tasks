#include<iostream>
#include<string>
using namespace std;
int main(int argc,char*argv[]){
int array[5];
int sum=0;
int *e=array;
for(int i=0;i<5;i++){//started from 1 since argv[index] where index is 1 and onwards
    *(e+i)=stoi(argv[i+1]);
}
for(int i=0;i<5;i++){
    sum = sum+*(e+i);
}
cout<<sum;
    return 0;
}