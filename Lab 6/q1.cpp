#include<iostream>
#include<string>
using namespace std;
class Books{
    public:
    string genre;
    Books(string genre):genre(genre){}
};
class derv1:public Books
{
    public:
    string title;
    string author;
    derv1(string title,string author,string genre):Books(genre){
        this->title=title;
        this->author=author;
    };
    void display(){
        cout<<"title:"<<title<<endl;
        cout<<"author:"<<author<<endl;
        cout<<"genre:"<<genre<<endl;
    }

};
class derv2:public Books
{
    public:
    string title;
    string author;
    derv2(string title,string author,string genre):Books(genre){
        this->title=title;
        this->author=author;
    };
    void display(){
        cout<<"title:"<<title<<endl;
        cout<<"author:"<<author<<endl;
        cout<<"genre:"<<genre<<endl;
    }

};
int main(){
  derv1 book1("never finished","david goggins","self-help");
  derv1 book2("cant hurt me","david goggins","novel");
  book1.display();
  book2.display();

}