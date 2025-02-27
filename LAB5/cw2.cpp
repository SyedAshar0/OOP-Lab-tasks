#include<iostream>
#include<vector>
using namespace std;
class Car{
public:
string name;
int id;
Car(string name,int id){
   this->name=name;
   this->id=id;
}
};
class Garage{
    public:
  Car* car;
  vector<Car*>cars;
  void ParkCar(Car* car){
    cars.push_back(car);
  }
  void listCars(){
    for(int i=0;i<cars.size();i++){
        cout<<"name:"<<cars[i]->name<<endl;
        cout<<"id:"<<cars[i]->id<<endl;
    }
  }
};


int main(){
   Car car1("toyota",100);
   Car  car2("nissan",900); 
   Car  car3("hyundai",800);
   Garage garage;
   garage.ParkCar(&car1); 
    garage.ParkCar(&car2); 
   garage.ParkCar(&car3);
   garage.listCars(); 



    return 0;
}