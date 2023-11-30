#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include <vector>

#include "seat.h" // Lami added this line of code

using namespace std;

class Flight;

class Passenger
{
private:
    int passengerID;
    string firstName;
    string lastName;
    int phoneNumber;
    Flight *passengerSeat; // FLIGHT CLASS

public:
    Passenger(int id, string fName, string lName, int phone, Seat *seat);
    Passenger(const Passenger &other);
    ~Passenger() {}

    int getPassengerID() const { return passengerID; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    int getPhoneNumber() const { return phoneNumber; }
    Flight *getPassengerSeat() const { return passengerSeat; }

    void setPassengerID(int id) { passengerID = id; }
    void setFirstName(const string &fName) { firstName = fName; }
    void setLastName(const string &lName) { lastName = lName; }
    void setPhoneNumber(int phone) { phoneNumber = phone; }
    // void setPassengerSeat(Seat* seat) { passengerSeat = seat; } // Lami commented this line of code
    void showPassengerInfo(); // Lami added this line of code
};

#endif // PASSENGER_H