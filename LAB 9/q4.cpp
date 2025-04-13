#include<iostream>
using namespace std;
class Student
{
    public:
virtual void getTuition(string status,int cred)=0;
};
class GraduateStudent:public Student
{
    private:
    string topic;
    public:
    void setTopic(string T)
    {
        topic=T;
    }
    string getTopic()
    {
        return topic;
    }
void getTuition(string status,int cred)override
{
if(status=="Undergraduate")
{
    cout<<"tuition fee:"<<200*cred<<endl;
}else if(status=="Graduate")
{
    cout<<"tuition fee:"<<300*cred<<endl;
}else if(status =="Doctoral")
{
    cout<<"tuition fee:"<<400*cred<<endl;
}else
{
    cout<<"invalid status"<<endl;
}
}
};
int main()
{
    GraduateStudent grad;
    int hrs=10;
    grad.setTopic("Machine learning");
    cout<<"Research Topic:"<< grad.getTopic()<< endl;
    grad.getTuition("Undergraduate",hrs);
    grad.getTuition("Graduate",hrs);
    grad.getTuition("Doctoral",hrs);
    return 0;
}