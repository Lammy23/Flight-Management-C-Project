#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>

using namespace std;

#include "seat.h"

class Passenger
{
private:
    int passengerID;
    string firstName;
    string lastName;
    string phoneNumber;
    Seat *passengerSeat;

public:
    Passenger();
    Passenger(int id, string fName, string lName, string phone, Seat *seat);
    Passenger(const Passenger &other);
    bool operator==(const Passenger &other) const { return passengerID == other.passengerID; };
    bool operator!=(const Passenger &other) const { return passengerID != other.passengerID; };

    int getPassengerID() const;
    string getFirstName() const;
    string getLastName() const;
    string getPhoneNumber() const;
    Seat *getPassengerSeat() const;

    void setPassengerID(int id);
    void setFirstName(const string &fName);
    void setLastName(const string &lName);
    void setPhoneNumber(string phone);
    void setPassengerSeat(Seat *seat);

    void showInfo();
};

#endif // PASSENGER_H