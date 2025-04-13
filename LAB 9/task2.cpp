#include<iostream>
#include<vector>
using namespace std;
class Logger
{
    private:
    vector<string>messages;
    //severity method
    void storingLogic(const string&prefix,const string&text)
    {
        string temp="{"+prefix+"}" + text;//formattng style such that the prefix stores the log
        if(messages.size()>=1000)//if exceedes limit
        {
            messages.erase(messages.begin());//erasure of a previous log at given position
        }
        messages.push_back(temp);//store it in the vector list
    }
    public:
    void logInfo(const string& text)
    {
      storingLogic("INFO",text);
    }
    void logWarning(const string& text)
    {
        storingLogic("WARN",text);

    }
    void logError(const string& text)
    {
        storingLogic("ERROR",text);
    }
    vector<string>getMessages()
    {
        return messages;
    }
};
class Auditor
{
    public:
    bool authenticated=false;
    void authentication(const string&password)
    {
        if(password=="WHYYYYY")
        {
            authenticated=true;
        }
    }
    void auditing(Logger &logger)
    {
       if(!authenticated)
       {
        cout<<"failed authentication"<<endl;
        return;
       }
       vector<string>Messages=logger.getMessages();
       for(const auto&key:Messages)
       {
        cout<<key<<endl;
       }
    }
};
int main()
{
Logger logger;
Auditor auditor;
logger.logInfo("Network stabilized");
logger.logError("Data nodule error");
auditor.auditing(logger);
auditor.authentication("YESSSSSSS");
auditor.authentication("WHYYYYY");
auditor.auditing(logger);
 return 0;
}