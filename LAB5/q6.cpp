#include<iostream>
#include<vector>
#include<string>
using namespace std;
class CoffeeShop{
    private:
    vector<string>Menuitems;
    vector<string>Menutypes;
    vector<double>price;
    vector<string>Orders;
    public:
    const string name;
    CoffeeShop(string n): name(n){};
    void addMenuItem(string x, string y, double z) {
        Menuitems.push_back(x);
        Menutypes.push_back(y);
        price.push_back(z);
    }
    void addOrder(string x){
          for(int i=0;i<Menuitems.size();i++){
            if(Menuitems[i]==x){
                Orders.push_back(x);
                cout<<x<<" has been added"<<endl;
                return;
            }
      }   
    cout<<"This item is currently unavailable"<<endl;

    }
    void fulfillOrder(){
        if(Orders.empty()){
          cout<<"all orders have been fullfilled"<<endl;
        }else{
          cout<<"the item :"<<Orders.front()<<" "<<"is ready"<<endl;
             Orders.erase(Orders.begin());
          }
        }
    void listOrders(){
        if(Orders.empty()){
           cout<<"no orders"<<endl;
        }else{
          for(int i=0;i<Orders.size();i++){
            cout<<"order:"<<i+1<<endl;
              cout<<Orders[i]<<endl;
            }
        }
    }
        double dueAmount(){
            double cost=0.0;
            for(const string &order:Orders){
                for(int i=0;i<Menuitems.size();i++){
                    if(Menuitems[i]==order){
                        cost+=price[i];
                    }
                }
            }
       return cost; 
        }
         string cheapestItem(){
             if(Menuitems.empty()){
                return "no avaliable items";
             }
             int index=0;
            for(int i=1;i<price.size();i++){
              if(price[i]<price[index]){
                index=i;
              }
            }
            return Menuitems[index];
          }
          void drinksOnly(){
            for(int i=0;i<Menuitems.size();i++){
              if(Menutypes[i]=="drinks"){
                cout<<"drink:"<<i+1<<endl;
                cout<<Menuitems[i]<<endl;
              }
            }
          }
          void foodOnly(){
            for(int i=0;i<Menuitems.size();i++){
              if(Menutypes[i]=="food"){
                cout<<"Food:"<<i+1<<endl;
                cout<<Menuitems[i]<<endl;
              }
            }
        }
};
int main(){
    CoffeeShop myShop("karachi darbar");
    myShop.addMenuItem("Hot Chocolate", "drink", 4.0);
    myShop.addMenuItem("Zinger Burger", "food", 50.0);
    myShop.addMenuItem("Divine Slush", "drink", 5.0);
    myShop.addMenuItem("Hot Potato", "food", 27.0);
    cout << "<--- Food Info --->\n";
    myShop.foodOnly();
    cout << "<--- Drinks Info --->\n";
    myShop.drinksOnly();
    cout << "Cheapest item: " << myShop.cheapestItem() << endl;
    cout << "...Adding orders...\n";
    myShop.addOrder("Hot Chocolate");
    myShop.addOrder("Hot Potato");
    myShop.addOrder("Tea");
    myShop.listOrders();
    cout << "Total cost: $" << myShop.dueAmount() << endl;
    myShop.fulfillOrder();
    myShop.listOrders();
    myShop.fulfillOrder();
    myShop.listOrders();



    return 0;
}

