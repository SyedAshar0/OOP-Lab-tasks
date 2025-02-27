#include<iostream>

using namespace std;
class Car{
    public:
    mutable int engineHP;
    mutable int capacity;
    mutable int num_speakers;
    Car(){
        engineHP=650;
        capacity=4;
        num_speakers=2;
    }
    void change() const{
        engineHP=700;
        capacity=6;
        num_speakers=4;
    }
};
int main(){
     Car cars;
     cout<<"<-----before change----->"<<endl;
     cout<<"horsepower:"<<" "<<cars.engineHP<<endl;
     cout<<"capacity:"<<" "<<cars.capacity<<endl;
     cout<<"speakers:"<<" "<<cars.num_speakers<<endl;
     cars.change();
     cout<<"<-----after change----->"<<endl;
     cout<<"horsepower:"<<" "<<cars.engineHP<<endl;
     cout<<"capacity:"<<" "<<cars.capacity<<endl;
     cout<<"speakers:"<<" "<<cars.num_speakers<<endl;
    return 0;
}