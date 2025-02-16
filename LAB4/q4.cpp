#include<iostream>
#include<string>
using namespace std;
class Books{
    public:
    string author;
    string title;
    double price;
    string publisher;
    int stockPosition;
    Books(){
        price=0.0;
        stockPosition=0;
    }
    Books(string author,string title,double price,string publisher,int stockPosition){
        this->author=author;
        this->title=title;
        this->price=price;
        this->publisher=publisher;
        this->stockPosition=stockPosition;
    }
     void check(Books books[],int n,string Title,string Author,int copies){
    bool flag=false;
    for(int i=0;i<n;i++){
       if(books[i].title==Title && books[i].author==Author){
        flag=true;
        cout<<"book found"<<endl;
        cout<<"author:"<<books[i].author<<endl;
          cout<<"title:"<<books[i].title<<endl;
          cout<<"price:"<<books[i].price<<endl;
          cout<<"publisher:"<<books[i].publisher<<endl;
           if(books[i].stockPosition>=copies){
            double cost=copies*books[i].price;
            cout<<"total cost:"<<cost<<endl;
           }else{
            cout<<"requested copies not in stock"<<endl;
           }
           return;
       }
    }
       if(!flag){
        cout<<"the requested book is not avaliable in the inventory"<<endl;
       }
    }
};
int main(){
    int n;
    cout<<"enter number of books to be added in the inventory:"<<endl;
    cin>>n;
    Books *books=new Books[n];
    for(int i=0;i<n;i++){
        cout<<"BOOK:"<<i+1<<endl;
        cout<<"author:"<<endl;
        cin>>books[i].author;
        cout<<"title:"<<endl;
        cin>>books[i].title;
        cout<<"price:"<<endl;
        cin>>books[i].price;
        cout<<"publisher:"<<endl;
        cin>>books[i].publisher;
        cout<<"stock position:"<<endl;
        cin>>books[i].stockPosition;
    }
    string s_title,s_author;
    int copiesreq;
    cout<<"enter title:"<<endl;
    cin>>s_title;
    cout<<"enter author:"<<endl;
    cin>>s_author;
    cout<<"enter copies:"<<endl;
    cin>>copiesreq;
    books->check(books,n,s_title,s_author,copiesreq);
    delete[] books;
}