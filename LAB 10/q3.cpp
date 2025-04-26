#include<iostream>
#include<fstream>
#include<vector>
#include<cstring> // for strcmp
using namespace std;
struct user
 {
    int userID;
    char first_name[50];
    char last_name[50];
    char address[100];
    char email[100];
};
struct orders
 {
    int order_ID;
    int userID;
    int product_ID;
    double totalPaid;
};
struct Product
 {
    int product_ID;
    char product_name[100];
    char description[200];
    double price;
};
void AddingData() {
    ofstream userFile("user.dat", ios::binary);
    ofstream productFile("product.dat", ios::binary);
    ofstream orderFile("order.dat", ios::binary);
    user u1 = {1, "Linus", "trabzonspar", "orangi town", "Linusworks@gmail.com"};
    user u2 = {2, "Arda", "Guler", "maloir", "generationalTalent@gmail.com"};
    Product p1 = {101, "Laptop", "High performance laptop", 1200};
    Product p2 = {102, "Mouse", "Wireless mouse", 40};
    Product p3 = {103, "Keyboard", "Mechanical keyboard", 100};
    orders o1 = {121, 1, 101, 1200}; 
    orders o2 = {122, 1, 102, 40};   
    orders o3 = {123, 2, 103, 100};  
    userFile.write((char*)&u1, sizeof(user));
    userFile.write((char*)&u2, sizeof(user));
    productFile.write((char*)&p1, sizeof(Product));
    productFile.write((char*)&p2, sizeof(Product));
    productFile.write((char*)&p3, sizeof(Product));
    orderFile.write((char*)&o1, sizeof(orders));
    orderFile.write((char*)&o2, sizeof(orders));
    orderFile.write((char*)&o3, sizeof(orders));
    userFile.close();
    productFile.close();
    orderFile.close();
}

void fetching() {
    ifstream userFile("user.dat", ios::binary);
    ifstream orderFile("order.dat", ios::binary);
    ifstream productFile("product.dat", ios::binary);
    if(!userFile || !orderFile || !productFile) {
        cout << "One or more files could not be opened!" << endl;
        return;
    }
    user u;
    int linusId = -1;
    while (userFile.read((char*)&u,sizeof(user))) {
        if (strcmp(u.first_name,"Linus")==0) {
            linusId = u.userID;
            break;
        }
    }
    userFile.close();
    if (linusId == -1) {
        cout << "Linus not found!" << endl;
        return;
    }
    vector<int> productIds;
    orders o;
    while(orderFile.read((char*)&o,sizeof(orders))) {
        if(o.userID==linusId) {
            productIds.push_back(o.product_ID);
        }
    }
    orderFile.close();
    Product p;
    cout<<"Products ordered by Linus:"<<endl;
    for(int pid:productIds) 
    {
        productFile.clear();
        productFile.seekg(0);
        while(productFile.read((char*)&p,sizeof(Product))){
            if (p.product_ID==pid){
                cout<<"->"<<p.product_name<<endl;
                break;
            }
        }
    }
    productFile.close();
}
int main() {
    AddingData();
    fetching();  
     return 0;
}
