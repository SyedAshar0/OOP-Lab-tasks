#include<iostream>
#include<string>
using namespace std;
class MenuItem{
  public:
  string item;
  string type;
  double price;
};
class CoffeeShop{
  public:
  string Name;
  MenuItem *Menu;
  string *Orders;
  int size;
  int capacity;
  int count;
  CoffeeShop(int w,int x){
    size=w;
    capacity=x;
    count=0;
    Orders=new string[capacity];//empty array allocated memory
    Menu=new MenuItem[size];
  }
  void addOrder(string itemname){
    bool flag=false;
    for(int i=0;i<size;i++){
      if(Menu[i].item==itemname){
        flag=true;
        Orders[count]=itemname;
        count++;
        break;
      }
    }
    if(!flag){
      cout<<"item is currently unavaliable"<<endl;
    }
  }
  void fullfillOrder(){
      if(count==0){
        cout<<"all orders have been fullfilled"<<endl;
      }else{
        cout<<"the item :"<<Orders[0]<<" "<<"is ready"<<endl;
        for(int i=0;i<count;i++){
          Orders[i]=Orders[i+1];
        }
        count--;
      }
  } 
  string *listOrders(){
    if(count==0){
      return nullptr;
    }else{
      for(int i=0;i<count;i++){
        cout<<"order:"<<i+1<<endl;
          cout<<Orders[i]<<endl;
        }
      }
      return Orders;
    }
  double dueAmount(){
     double cost=0.0;
     for(int i=0;i<count;i++){
      for(int j=0;j<size;j++){
          if(Orders[i]==Menu[j].item){
            cost+=Menu[j].price;
          }
      }
        
}
return cost; 
 }
  string cheapestItem(){
    MenuItem cheapest=Menu[0];
    for(int i=0;i<size;i++){
      if(Menu[i].price<cheapest.price){
        cheapest=Menu[i];
      }
    }
    return cheapest.item;
  }
  void drinksOnly(){
    for(int i=0;i<size;i++){
      if(Menu[i].type=="drinks"){
        cout<<"drink:"<<i+1<<endl;
        cout<<Menu[i].item<<endl;
      }
    }
  }
  void foodOnly(){
    for(int i=0;i<size;i++){
      if(Menu[i].type=="food"){
        cout<<"Food:"<<i+1<<endl;
        cout<<Menu[i].item<<endl;
      }
    }
  }
  ~CoffeeShop(){
    delete[] Orders;
    delete[] Menu;
  }

};
int main(){
CoffeeShop coffee(4,4);
coffee.Menu[0]={"Hot chocolate","drinks",6.0};
coffee.Menu[1]={"Zinger burger","food",10.0};
coffee.Menu[2]={"Divine slush","drinks",4.0};
coffee.Menu[3]={"Hot potato","food",25.0};
cout<<"<-----Foods info----->"<<endl;
coffee.foodOnly();
cout<<"<-----drinks info----->"<<endl;
coffee.drinksOnly();
cout<<"cheapest item:"<<coffee.cheapestItem()<<endl;
cout<<"...Adding orders..."<<endl;
coffee.addOrder("Hot chocolate");
coffee.addOrder("Hot potato");
coffee.listOrders();
cout<<"----------"<<endl;
cout<<"cost:"<<coffee.dueAmount()<<endl;
cout<<"----------"<<endl;
coffee.fullfillOrder();
coffee.listOrders();
coffee.fullfillOrder();
coffee.listOrders();
  return 0;
}