#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

#include "headers/passenger.h"

using namespace std;

Passenger::Passenger(int id, string fName, string lName, string phone, Seat *seat)
{

    passengerID = id;
    firstName = fName;
    lastName = lName;
    phoneNumber = phone;
    passengerSeat = seat;
    passengerSeat->setStatus(true);
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
Seat *Passenger::getPassengerSeat() const
{

    cout << "Passenger Seat: " << passengerSeat->getColumnLetter() << passengerSeat->getRowNumber() << endl;
    return passengerSeat;
}

void Passenger::setPassengerID(int id) { passengerID = id; }
void Passenger::setFirstName(const string &fName) { firstName = fName; }
void Passenger::setLastName(const string &lName) { lastName = lName; }
void Passenger::setPhoneNumber(string phone) { phoneNumber = phone; }
void Passenger::setPassengerSeat(Seat *seat)
{
    passengerSeat = seat;
    passengerSeat->setStatus(true);
}

void Passenger::showInfo()
{
    cout << setw(20) << left << firstName << setw(20) << left << lastName << setw(20) << left << phoneNumber << setw(5) << left << passengerSeat->getRowNumber() << setw(5) << left << passengerSeat->getColumnLetter() << setw(10) << left << passengerID << endl;
    // cout << firstName << "\t\t" << lastName << "\t\t" << phoneNumber << "\t\t" << passengerSeat->getRowNumber() << "\t\t" << passengerSeat->getColumnLetter() << "\t\t" << passengerID << endl;
}