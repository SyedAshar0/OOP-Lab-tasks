#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    fstream f;
    f.open("foile1.txt",ios::app);
     if(!f)
    {
        cout<<"file aint avaliable"<<endl;
        return 1;
    }
    string str[100];//buffer
    cout<<"enter tasks:"<<endl;
    for(int i=0;i<3;i++)
    {
        getline(cin,str[i]);
        f<<str[i]<<endl;
    }
   f.close();
   ifstream FIN("foile1.txt");
   int count=0;
   //setting count as index
   while(getline(FIN,str[count]))
   {
      count++;
   }
   FIN.close();
   int index;
   cout<<"enter index of task to be marked as done:"<<endl;
   cin>>index;
   if(index>=1 && index<=count)
   {
    str[index-1]+= " (done)";
   }else
   {
    cout<<"invalid index"<<endl;
    return 1;
   }
   ofstream FOUT("foile1.txt");
   for(int i=0;i<count;i++)
   {
    FOUT<<str[i]<<endl;
   }
   FOUT.close();
   cout<<"TASKS:"<<endl;
   for(int i=0;i<count;i++)
   {
    cout<<i+1<<":"<<str[i]<<endl;
   }
    return 0;
}