#include<iostream>
#include<vector>
using namespace std;
class Doctor;
class Billing;
class PatientRecord
{
    string name;
    string ID;
    string DOB;
    vector<string>medicalHistory;
    vector<string>currentTreatments;
    vector<string>BillingInfo;
    friend class Doctor;
    friend class Billing;
    void getMedicalData()
    {
        for(const auto& key:medicalHistory)
        {
            cout<<key<<endl;
        }
        for(const auto& key:currentTreatments)
        {
            cout<<key<<endl;
        }

    }
     void getBillingInfo()
     {
        for(const auto& key:BillingInfo)
        {
            cout<<key<<endl;
        }
     }
     public:
    PatientRecord(string name,string ID,string DOB,vector<string>medicalHistory,vector<string>currentTreatments):name(name),ID(ID),DOB(DOB),medicalHistory(medicalHistory),currentTreatments(currentTreatments){}
    void getPublicData()
    {
        cout<<"name:"<<name<<endl;
        cout<<"id:"<<ID<<endl;
        cout<<"DOB:"<<DOB<<endl;
    }
};
class Doctor
{
    public:
    void updateMedicalHistory(PatientRecord *record,const string text)
    {
       record->medicalHistory.push_back(text);
       cout<<"history updated"<<endl;
    }
    void viewMedicalData(PatientRecord *record)
    {
        record->getMedicalData();
    }
};
class Billing
{
public:
void addBillingDetails(PatientRecord * record,const string newData)
{
   record->BillingInfo.push_back(newData);
   cout<<"data added to bill"<<endl;
}
void viewBllingInfo(PatientRecord * record)
{
record->getBillingInfo();
}

};
class Receptionist
{
    public:
    void testing(PatientRecord *record)
    {
        cout<<"can access this funciton only"<<endl;
        record->getPublicData();
        cout<<"this class does not have access to this commented function"<<endl;
        // record->getMedicalData();
    }
};
int main() {
    vector<string> history = {"Asthma","Migraine"};
    vector<string> treatments = {"Inhaler","Painkillers"};
    PatientRecord patient("Ashar","0582","21/09/2004",history,treatments);
    Doctor doc;
    Billing bill;
    cout<<"medical data:";
    doc.viewMedicalData(&patient);
    cout<<"updating medical history:"<<endl;
    doc.updateMedicalHistory(&patient, "High blood pressure");
    cout<<"adding billing info:"<<endl;
    bill.addBillingDetails(&patient, "MRI Scan - Rs8000");
    cout<<"viewing billing info:"<<endl;
    bill.viewBllingInfo(&patient);
    cout<<"data view:"<<endl;
    patient.getPublicData();
    cout<<" Receptionist trying to access medical data:"<<endl;
    Receptionist r;
    // The line below will cause a compilation error if getMedicalData() is private:
    // r.testing(&patient);
    cout << "Access denied.\n";
    return 0;
}

