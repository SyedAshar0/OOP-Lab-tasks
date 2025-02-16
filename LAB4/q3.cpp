#include<iostream>
#include<string>
using namespace std;
class Invoice{
    public:
    string part_num;
    string part_desc;
    int quantity;
    double ppi;
    Invoice(string part_num,string part_desc,int quantity,double ppi){
        this->part_num=part_num;
        this->part_desc=part_desc;
        this->quantity=quantity;
        this->ppi=ppi;
    }
    double getAmount(){
        return quantity*ppi;
    }
    void settter(){
        if(quantity<0 || ppi<0){
            quantity=0;
            ppi=0.0;
        }
    }
};
int main(int argc,char * argv[]){
Invoice invoice=Invoice(argv[1],argv[2],stoi(argv[3]),stod(argv[4]));
invoice.settter();
cout<<"invoice amount:"<<invoice.getAmount()<<endl;









    return 0;
}