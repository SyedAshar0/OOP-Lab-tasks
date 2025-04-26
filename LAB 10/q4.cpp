#include<iostream>
#include<fstream>
#include<cstring>
#include<cerrno>//for finding specific error
#include<unistd.h>//for renaming
using namespace std;
int main()
{
    fstream f("log1.txt", ios::binary | ios::in | ios::out | ios::ate);//used biaary so i can use tellg to find size of the file
    if (!f)
    {
        cout<<"Error opening file:"<< strerror(errno) << endl;
        //explicitly creating log1.txt file
        ofstream foile("log1.txt");
        if (!foile)
        {
            cout << "Error creating file: " << strerror(errno) << endl;
            return 1;
        }
        cout << "File created successfully!" << endl;
        foile.close();
        
        // Reattempt at opening the file after creation
        f.open("log1.txt", ios::binary | ios::in | ios::out | ios::ate);
        if (!f)
        {
            cout<<"Error opening file after creation:"<<strerror(errno)<<endl;
            return 1;
        }
    }
    //writing to file
    char ch = 'X';
    size_t target = 1 * 1024 * 1024; 
    size_t count = 0;
    while (count < target)
    {
        f.write(&ch, 1);//writing X once iteratively till count<target
        count++;
    }
    //finding size
    streamsize size=f.tellg();
    cout<<"File size:"<<size/(1024.0*1024.0)<<"MB"<< endl;
    f.close();
    //renaming
    if (size>=target)
    {
        cout<<"The file has reached/exceeded 1MB,renaming now...."<<endl;
        if (rename("log1.txt","log2.txt")!=0)
        {
            cout<<"Error renaming file:"<<strerror(errno) << endl;
            return 1;
        }
    }
    ofstream fout("log1.txt");//creating new file
    if(!fout)
    {
        cout << "Error opening file: " << strerror(errno) << endl;
        return 1;
    }
    fout<<"New entry"<<endl;//writing to it
    fout.close();
    return 0;
}
