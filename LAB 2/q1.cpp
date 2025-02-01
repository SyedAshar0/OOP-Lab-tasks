#include<iostream>
using namespace std;
int main(int argc,char*argv[]){
   int array[argc-1];
   int *ptr=array;
   for(int i=1;i<argc;i++){
     ptr[i-1]=stoi(argv[i]);
   }
   int sum=0;
   for(int i=0;i<argc-1;i++){
    sum=sum+ptr[i];
   }
   cout<<sum<<endl;




return 0;
}