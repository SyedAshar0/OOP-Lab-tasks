#include<iostream>
#include<string>
using namespace std;
class Vehicles{
    public:
    float price;
    Vehicles(float price):price(price){};
};
class Car:public Vehicles{
    public:
    int capacity;
    int n_doors;
    string fueltype;
    Car(float price,int capacity,int n_doors,string fueltype):Vehicles{price}{
        this->capacity=capacity;
        this->n_doors=n_doors;
        this->fueltype=fueltype;
    };
};
class Motorcycle:public Vehicles{
    public:
    int n_cylinders;
    int n_gears;
    int n_wheels;
    Motorcycle(float price,int n_cylinders,int n_gears,int n_wheels):Vehicles{price}{
        this->n_cylinders=n_cylinders;
        this->n_gears=n_gears;
        this->n_wheels=n_wheels;
    };

};
class Audi:public Car{
    public:
string model;
Audi(float price,int capacity,int n_doors,string fueltype,string model):Car(price,capacity,n_doors,fueltype){
    this->model=model;
};

};
class Yamaha:public Motorcycle{
public:
string make;
Yamaha(float price,int n_cylinder,int n_gears,int n_wheels,string make):Motorcycle(price,n_cylinder,n_gears,n_wheels){
this->make=make;
}
};
int main(){
  Audi audi(500,8,4,"petrol","xlr8");
  Yamaha yamaha(1200,2,5,2,"mt103");
  cout<<"<-----Audi----->"<<endl;
  cout<<"price:"<<audi.price<<endl;
  cout<<"seating capacity:"<<audi.capacity<<endl;
  cout<<"number of doors:"<<audi.n_doors<<endl;
  cout<<"fuel type:"<<audi.fueltype<<endl;
  cout<<"model type:"<<audi.model<<endl;
  cout<<"<-----=Yamaha----->"<<endl;
  cout<<"price:"<<yamaha.price<<endl;
  cout<<"number of cylinders:"<<yamaha.n_cylinders<<endl;
  cout<<"number of gears:"<<yamaha.n_gears<<endl;
  cout<<"number of wheels:"<<yamaha.n_wheels<<endl;
  cout<<"make-type:"<<yamaha.make<<endl;

}