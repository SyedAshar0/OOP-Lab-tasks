#include<iostream>
#include<string>
using namespace std;
class Book{
public:
string book_name;
int ISBN;
string author;
string publisher;
//since im creating an array of objects,i need a default constructor bcz without it the compiler will try to produce all objects at once hence error 
Book()
{
     }
Book(string book_name,int ISBN,string author,string publisher){//now this parametrixed constructor is the main part with this keyword for each object
this->book_name=book_name;
this->ISBN=ISBN;
this->author=author;
this->publisher=publisher;
}
void getBookinfo(){
    cout<<this->book_name<<" "<<this->ISBN<<" "<<this->author<<" "<<this->publisher<<" "<<endl;
}
};
int main(){
    string n;
    int isbn;
    string auth;
    string pub;
    Book BookTest[5];
for(int i=0;i<5;i++){
    cout<<"object:"<<i+1<<endl;
   cin>>n;
   cin>>isbn;
   cin>>auth;
   cin>>pub;
   BookTest[i]=Book(n,isbn,auth,pub);
}
for(int i=0;i<5;i++){
    cout<<"object:"<<i+1<<endl;
    BookTest[i].getBookinfo();
}



return 0;
}
