#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "headers/passenger.h"

using namespace std;

Passenger::Passenger(int id, string fName, string lName, string phone, string *seat)
{

    passengerID = id;
    firstName = fName;
    lastName = lName;
    phoneNumber = phone;
    passengerSeat = seat;
}

Passenger::Passenger()
{

    passengerID = 0;
    firstName = "Unavailable";
    lastName = "Unavailable";
    phoneNumber = "Unavailable";
    passengerSeat = nullptr;
}

Passenger::Passenger(const Passenger &other)
{

    passengerID = other.passengerID;
    firstName = other.firstName;
    lastName = other.lastName;
    phoneNumber = other.phoneNumber;
    passengerSeat = other.passengerSeat;
}

int Passenger::getPassengerID() const { return passengerID; }
string Passenger::getFirstName() const { return firstName; }
string Passenger::getLastName() const { return lastName; }
string Passenger::getPhoneNumber() const { return phoneNumber; }
string *Passenger::getPassengerSeat() const { return passengerSeat; }

void Passenger::setPassengerID(int id) { passengerID = id; }
void Passenger::setFirstName(const string &fName) { firstName = fName; }
void Passenger::setLastName(const string &lName) { lastName = lName; }
void Passenger::setPhoneNumber(string phone) { phoneNumber = phone; }
void Passenger::setPassengerSeat(string *seat) { passengerSeat = seat; }