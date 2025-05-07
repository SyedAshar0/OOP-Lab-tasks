#include<iostream>
#include<exception>
using namespace std;
class ArrayIndexOutOfBounds:public exception
{
    public:
    const char* what() const noexcept override
    {
        return "the array index are out of bounds";
    }
};
template<class T>
class SafeArray{
    public:
    T *array;
    int n;
    SafeArray(int n):n(n)
    {
        array=new T[n];
    }
    //operator overloading
    T& operator [](int id)
    {
        if(id<0 || id>=n)
        {
            throw ArrayIndexOutOfBounds();
        }
        return array[id];
    }

};
int main()
{
    SafeArray<int>array(5);
    try{
        //normal behavior
      array[1]=12;
      cout<<"array at index 1:"<<array[1]<<endl;
      //triggering exception handling
      array[6]=10;
      cout<<"array at index 6:"<<array[6]<<endl;
      
    }catch(const ArrayIndexOutOfBounds &e)
    {
        cout<<"error:"<<e.what()<<endl;
    }
    

 return 0;
}