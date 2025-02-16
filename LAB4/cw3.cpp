#include<iostream>
#include<string>
using namespace std;
class DynamicArray{
    public:
    int *Arr;
    int size;
    DynamicArray(){
        size=0;
        Arr[size];
    }
    DynamicArray(int n){
        size=n;
        Arr=new int[size];
        for(int i=0;i<size;i++){
            Arr[i]=0;
        }
    }
    //copy
    DynamicArray(const DynamicArray&other){
        size=other.size;
        Arr=new int[size];
        for(int i=0;i<size;i++){
            Arr[i]=other.Arr[i];
        }
    };
     DynamicArray& operator=(const DynamicArray&other){
         if(this!=&other){
             delete []Arr;
             size=other.size;
             Arr=new int[size];
             for(int i=0;i<size;i++){
                Arr[i]=other.Arr[i];
             }
         }
         return *this;
     }
    //move 
    DynamicArray(DynamicArray&&other) noexcept: Arr(other.Arr){
        size=other.size;
        other.size=0;    
    };
    DynamicArray& operator=(DynamicArray&&other)noexcept {
        if(this!=&other){
            delete[] Arr;
            Arr=other.Arr;
            size=other.size;
            other.Arr=nullptr;
            other.size=0;
        }
        return *this;
    } 
     ~DynamicArray(){
        delete[] Arr;
    }
    int Size(){
       return size;
    }
    int& at(int index){ 
       for(int i=0;i<sizeof(Arr);i++){
             if(i==index){
                break;
             }
       }
       return Arr[index];
    }
    const int& at(int index) const{
        return Arr[index];
    }
    void resize(int newSize){
        int* newArr=new int[newSize];
        for(int i=0;i<newSize;i++){
           newArr[i]=Arr[i];
        }
        delete[] Arr;
        Arr=newArr;
        size=newSize;
    }  
};
int main(){
    DynamicArray obj1(10);
    obj1.at(4)=50;
    cout<<"element at 4th index is:"<<obj1.at(4)<<endl;;
    DynamicArray obj2=obj1;
    obj2.at(4)=60;
    DynamicArray obj3=move(obj1);
    cout<<"size of object 3 is:"<<obj3.Size()<<endl;;
return 0;
}