#include<iostream>


using namespace std;
void* add(void* ptr,int argc){
    int* Array=(int*)ptr;
     for(int i=0;i<argc-1;i++){
       Array[i]++;
     }    
     return ptr;

}

int main(int argc,char* argv[]){
    int array[argc-1];
    int* ptr=array;
    for(int i=1;i<argc;i++){
        ptr[i-1]=stoi(argv[i]);
    }
    void* mew=add(ptr,argc);
    int* kew=(int*)mew;
    for(int i=0;i<argc-1;i++){
        cout<<kew[i]<<endl;
    }

    return 0;
}