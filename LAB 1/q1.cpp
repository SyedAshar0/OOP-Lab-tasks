#include<iostream>
#include<string>

using namespace std;
int main(int argc,char*argv[]){
   float array[20];
   float *e=array;
   int max=-1;
   int s_max=-1;
   for(int i=0;i<20;i++){
    *(e+i)=stof(argv[i+1]);//since argv starts from 1st index and we want that the program name stays relevant so i+1 will allow us to start from argv[1]..
   }
   for(int i=0;i<20;i++){
       if(*(e+i)>max){
        s_max=max;
        max=*(e+i);
      }else if(*(e+i)>s_max && *(e+i)<max){
        s_max=*(e+i);
       }
   }
    cout<<s_max;
    return 0;
}