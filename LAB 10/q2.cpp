#include<iostream>
#include<fstream>
#include<cstring>
#include<cerrno>
#include<vector>
#include<iomanip>
#include<unistd.h>
#include<sstream>
using namespace std;

int main()
{
    // writing initial data
    ofstream f("QUERY.txt", ios::out);
    if(!f)
    {
        cout << "error:" << strerror(errno) << endl;
    }
    f << "dataID" << setw(15) << "name" << setw(15) << "designation" << setw(15) << "YOS" << endl;
    f << "0582" << setw(15) << "Syed" << setw(15) << "manager" << setw(15) << "2" << endl;
    f << "0583" << setw(15) << "Ashar" << setw(15) << "developer" << setw(15) << "1" << endl;
    f << "0584" << setw(15) << "Tahir" << setw(15) << "Head" << setw(15) << "7" << endl;
    f << "0585" << setw(15) << "Rahat" << setw(15) << "CFO" << setw(15) << "10" << endl;
    f.close();

    // searching query
    ifstream fin("QUERY.txt", ios::in);
    string line, designation, name;
    int id, YOS;
    bool heading = true;
    vector<string> original_lines;
    vector<string> incremented_lines;

    while(getline(fin, line))
    {
        if(heading)
        {
            original_lines.push_back(line); // keep heading
            incremented_lines.push_back(line); // also heading
            heading = false;
            continue;
        }

        istringstream ss(line);
        ss>>id>>name>>designation>>YOS;

        if(designation=="manager"&&YOS>=2)
        {
            cout<<name<<endl;
            original_lines.push_back(line);
            id++; 
            YOS++;
            ostringstream os;
            os<<id<<setw(15)<<name<<setw(15)<<designation<<setw(15)<<YOS;
            incremented_lines.push_back(os.str());
        }
    }
    fin.close();
    // writing to temp file
    ofstream fout("temp.txt", ios::out);
    if(!fout)
    {
        cout << "error:" << strerror(errno) << endl;
    }
    for(const auto &item : original_lines)
    {
        fout << item << endl;
    }
    for(int i = 1; i < incremented_lines.size(); i++)
    {
        fout<<incremented_lines[i]<<endl;
    }
    fout.close();
    remove("QUERY.txt");
    if(rename("temp.txt", "QUERY.txt") != 0)
    {
        cout<<"error:"<<strerror(errno)<<endl;
    }
    return 0;
}