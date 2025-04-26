#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    fstream f;
    f.open("foile.txt",ios::out);
    if(!f)
    {
        cout<<"file aint avaliable"<<endl;
        return 1;
    }
    string str;
    cout<<"enter string:"<<endl;
    getline(cin,str);
    f<<str<<endl;
    for(int i=0;i<str.length();i++)
    {
          str[i]=int(str[i])+i+1;
    }
    f<<str<<endl;
    for(int i=0;i<str.length();i++)
    {
          str[i]=int(str[i])-i-1;
    }
    f<<str<<endl;
    f.close();
    
   
}

