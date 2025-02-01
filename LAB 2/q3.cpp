#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(int argc,char *argv[]){
    int *array=new int[argc-1];
        for(int i=0;i<argc-1;i++){
            array[i]=stoi(argv[i+1]);
        }
            if(argc-1>=5){
                cout<<"limit reached,resizing"<<endl;
                int temp=argc-1;//temp to store the old size because it gets changed to new size
                int newtemp=2*temp;
                int *Array=new int[newtemp];
                memcpy(Array,array,temp*sizeof(int));//copying elements
                delete[] array;
                array=Array;
                for(int i=temp;i<newtemp;i++){
                    if(i<argc-1){
                    array[i]=stoi(argv[i+1]);
                }else{
                    array[i]=1;
                }
                }
            }
    for(int i=0;i<argc-1;i++){
        cout<<array[i]<<" ";
    }
    delete[] array;
    return 0;
    }