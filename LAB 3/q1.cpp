#include<iostream>
#include<string>
using namespace std;
class User{
    public:
    int Age;
    string Name;
};

int main(int argc,char*argv[]){
 User user;
 user.Name="Teo";
 user.Age=24;
cout<<"my Name is:"<<user.Name<<" "<<"and Im "<<user.Age<<" "<<"years old"<<" "<<endl;


return 0;

}
