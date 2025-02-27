#include<iostream>
using namespace std;
class Engine{
public:
bool isRunning;
void start(){
    cout<<"engine started"<<endl;
    isRunning=true;
    cout<<"status"<<" "<<isRunning<<endl;
}
void stop(){
    cout<<"engine stopped"<<endl;
    isRunning=false;
        cout<<"status"<<" "<<isRunning<<endl;

}
};
class Car{
private:
Engine  engine;
public:
Car(string name){
  cout<<name<<" "<<"constrcuted"<<endl;
}
~Car(){
    cout<<"destroyed"<<endl;
}
void startCar(){
engine.start();
}
void stopCar(){
engine.stop();
}
};
int main(){
Car obj("toyota");
obj.startCar();
obj.stopCar();



    return 0;
}
