#include<iostream>
using namespace std;
class Currency
{
    public:
    double amount;
    string CurrencyCode;
    string currencySymbol;
    double exchangeRate;
    Currency(double a,string cc,string cs,double er):amount(a),CurrencyCode(cc),currencySymbol(cs),exchangeRate(er){};
    virtual void convertToBase()=0;
    virtual void displayCurrency()
    {
        cout<<"amount:"<<amount<<endl;
        cout<<"currency code:"<<CurrencyCode<<endl;
        cout<<"currency Symbol:"<<currencySymbol<<endl;
        cout<<"exchange Rate:"<<exchangeRate<<endl;
    }
    virtual void convertTo(Currency& TaregtCurrency)=0;
};
class Dollar:public Currency
{
    public:
    Dollar(double a,string cc,string cs,double er):Currency(a,cc,cs,er){};
    void displayCurrency()override
    {
        Currency::displayCurrency();
    }
    void convertToBase()override
    {
        double baseAmount=amount*exchangeRate;
        cout<<"amount in base currecy:"<<baseAmount<<endl;
    }
    virtual void convertTo(Currency& TaregtCurrency)override;

};
class Rupee:public Currency{
    public:
    Rupee(double a,string cc,string cs,double er):Currency(a,cc,cs,er){};
    void displayCurrency()override
    {
        Currency::displayCurrency();
    }
    void convertToBase()override
    {
        double baseAmount=amount*exchangeRate;
        cout<<"amount in base currecy:"<<baseAmount<<endl;
    }
    virtual void convertTo(Currency& TaregtCurrency)override;
};
class Euro:public Currency
{
    public:
    Euro(double a,string cc,string cs,double er):Currency(a,cc,cs,er){};
    void displayCurrency()override
    {
        Currency::displayCurrency();
    }
    void convertToBase()override
    {
        double baseAmount=amount*exchangeRate;
        cout<<"amount in base currecy:"<<baseAmount<<endl;
    }
    virtual void convertTo(Currency& TaregtCurrency)override;
};
void Dollar::convertTo(Currency &TargetCurrency)
{
   if(Dollar * TargetDollar=dynamic_cast<Dollar*>(&TargetCurrency))
{
    cout<<"cant convert to same currecny"<<endl;
}else if(Rupee *TargetRupee=dynamic_cast<Rupee*>(&TargetCurrency))
{
    double convertedAmount=amount*(TargetRupee->exchangeRate/exchangeRate);
    cout<<"amount in rupees->"<<convertedAmount<<endl;
}else if(Euro *TargetEuro=dynamic_cast<Euro*>(&TargetCurrency))
{
    double convertedAmount=amount*(TargetEuro->exchangeRate/exchangeRate);
    cout<<"amount in euro->"<<convertedAmount<<endl;
}
}
void Rupee::convertTo(Currency &TargetCurrency)
{
   if(Rupee * TargetRupee=dynamic_cast<Rupee*>(&TargetCurrency))
{
    cout<<"cant convert to same currecny"<<endl;
}else if(Dollar *TargetDollar=dynamic_cast<Dollar*>(&TargetCurrency))
{
    double convertedAmount=amount*(TargetDollar->exchangeRate/exchangeRate);
    cout<<"amount in dollar->"<<convertedAmount<<endl;
}else if(Euro *TargetEuro=dynamic_cast<Euro*>(&TargetCurrency))
{
    double convertedAmount=amount*(TargetEuro->exchangeRate/exchangeRate);
    cout<<"amount in euro->"<<convertedAmount<<endl;
}
}
void Euro::convertTo(Currency &TargetCurrency)
{
   if(Euro * TargetEuro=dynamic_cast<Euro*>(&TargetCurrency))
{
    cout<<"cant convert to same currecny"<<endl;
}else if(Dollar *TargetDollar=dynamic_cast<Dollar*>(&TargetCurrency))
{
    double convertedAmount=amount*(TargetDollar->exchangeRate/exchangeRate);
    cout<<"amount in dollar ->"<<convertedAmount<<endl;
}else if(Rupee *TargetRupee=dynamic_cast<Rupee*>(&TargetCurrency))
{
    double convertedAmount=amount*(TargetRupee->exchangeRate/exchangeRate);
    cout<<"amount in rupee->"<<convertedAmount<<endl;
}
}
int main()
{
    Dollar dollar(100, "USD", "$", 1.0);
    Rupee rupee(7400, "PKR", "RS.", 0.0135);  
    Euro euro(85, "EUR", "Euro", 1.18); 
    dollar.displayCurrency();
    rupee.displayCurrency();
    euro.displayCurrency();
    dollar.convertToBase();
    dollar.convertTo(euro);
    rupee.convertToBase();
    rupee.convertTo(dollar);
    rupee.convertTo(euro);
    euro.convertToBase();
    euro.convertTo(rupee);
    euro.convertTo(dollar);
 return 0;
}