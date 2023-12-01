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
    ~Passenger();
    bool operator==(const Passenger &other) const { return passengerID == other.passengerID; };
    bool operator!=(const Passenger &other) const { return passengerID != other.passengerID; };

    int getPassengerID() const { return passengerID; };
    string getFirstName() const { return firstName; };
    string getLastName() const { return lastName; };
    string getPhoneNumber() const { return phoneNumber; };
    Seat *getPassengerSeat() const { return passengerSeat; };

    void setPassengerID(int id) { passengerID = id; };
    void setFirstName(string fName) { firstName = fName; };
    void setLastName(string lName) { lastName = lName; };
    void setPhoneNumber(string phone) { phoneNumber = phone; };
    void setPassengerSeat(Seat *seat);

    void showInfo(ostream &stream = cout);
};

#endif // PASSENGER_H