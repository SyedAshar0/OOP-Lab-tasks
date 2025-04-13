#include<iostream>
using namespace std;
class Passenger;
class Flight
{
    private:
    string flightNum;
    string departure;
    string arrival;
    int capacity;
    int count;
    public:
    Flight(string num,string d,string arrival,int capacity):flightNum(num),departure(d),arrival(arrival),capacity(capacity),count(0){};
    bool BookSeat()
    {
      if(count<capacity)
      {
        count++;
        return true;
      }
      return false;
    }
    bool cancelSeat()
    {
        if(count>0)
        {
            count--;
            return true;
        }
        return false;
    }
    bool upgradeSeat()
    {
     if(count>0)
     {
        cout<<"seat upgraded"<<endl;
        return true;
     }
     return false;
    }
    void Status() {
        cout<<"Flight:"<<flightNum<<" "<<departure<<"---->"<<arrival<<endl;
        cout<<"Booked Seats:"<<count<<endl;
    }
};
class Passenger
{
    string ID;
    string Name;
    public:
    Passenger(string ID,string Name):ID(ID),Name(Name){};
    void requestBooking(Flight &flight)
    {
        if(flight.BookSeat())
        {
            cout<<"seat booked"<<endl;
        }else{
            cout<<"cant book"<<endl;
        }
    }
    void requestCancellation(Flight &flight)
    {
        if(flight.cancelSeat())
        {
            cout<<"seat cancelled"<<endl;
        }else{
            cout<<"cant cancel"<<endl;
        }
    }
    void requestUpgrade(Flight &flight)
    {
        if(flight.upgradeSeat())
        {
            cout<<"seat upgraded"<<endl;
        }else{
            cout<<"cant upgrade"<<endl;
        }
    }
};
int main() {
    Flight flight("Boeing777", "Abu Dhabi", "Dubai", 2);
    Passenger p1("0582", "Syed");
    Passenger p2("0583", "Ashar");
    Passenger p3("0584", "Tahir");
    p1.requestBooking(flight);
    p2.requestBooking(flight);
    p3.requestBooking(flight); 
    flight.Status();
    p2.requestCancellation(flight);
    p3.requestBooking(flight); 
    p1.requestUpgrade(flight); 
    flight.Status();
    return 0;
}