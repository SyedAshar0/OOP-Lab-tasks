#include<iostream>
using namespace std;
class StackUnderflowException:public exception
{
    public:
    const char* what() const noexcept override
    {
        return "stack was indeed underflow";
    }
};
template<typename T>class Stack
{
    public:
    static const int Size=50;
    T array[Size];
    int topIndex;
    Stack()
    {
        topIndex=-1;
    }
    void push(const T &value)
    {
        array[++topIndex]=value;//pushing  value to topindex
    }
    T pop()
    {
        if(topIndex==-1)
        {
           throw StackUnderflowException();
        }
        return array[topIndex--];
    }
    T top()
    {
        if(topIndex==-1)
        {
           throw StackUnderflowException();
        }
        return array[topIndex];
    }
};
int main()
{
    Stack<int>stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout<<"element at the top:"<<stack.top()<<endl;
    cout<<"popped element:"<<stack.pop()<<endl;
    cout<<"popped element:"<<stack.pop()<<endl;
    try
    {
        cout<<"popped element:"<<stack.pop()<<endl;
        cout<<"popped element:"<<stack.pop()<<endl;
    }catch(StackUnderflowException &e)
    {
        cout<<"error:"<<e.what()<<endl;
    }

 return 0;
}