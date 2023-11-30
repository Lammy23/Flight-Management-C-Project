#include <string>
#include <vector>
#include <iostream>

#include "headers/flight.h"

using namespace std;

Flight::Flight(string flight_id, int rows, int columns)
{
    this->flight_id = flight_id;
    this->rows = rows;
    this->columns = columns;
    this->seat_map = vector<vector<string>>(rows, vector<string>(columns, "O"));
    this->passenger_list = vector<Passenger>();
}

Flight::Flight(const Flight &flight)
{
    this->flight_id = flight.flight_id;
    this->rows = flight.rows;
    this->columns = flight.columns;
    this->passenger_list = flight.passenger_list;
    this->seat_map = flight.seat_map;
}

Flight &Flight::operator=(const Flight &flight)
{
    if (this != &flight)
    {
        this->flight_id = flight.flight_id;
        this->rows = flight.rows;
        this->columns = flight.columns;
        this->passenger_list = flight.passenger_list;
        this->seat_map = flight.seat_map;
    }
    return *this;
}

void Flight::add_passenger(Passenger passenger)
{
    if (passenger_list.size() == rows * columns)
    {
        cout << "Flight is full" << endl;
        return;
    }
    passenger_list.push_back(passenger);
}

void Flight::remove_passenger(Passenger passenger)
{
    if (passenger_list.size() == 0)
    {
        cout << "No passengers on this flight" << endl;
        return;
    }

    for (int i = 0; i < passenger_list.size(); i++)
    {
        if (passenger_list[i].getPassengerID() == passenger.getPassengerID())
        {
            passenger_list.erase(passenger_list.begin() + i);
            cout << "Passenger removed" << endl;
            return;
        }
    }
    cout << "Passenger not found" << endl;
}

void Flight::showFlightSeatMap()
{
    // Implementation of showFlightSeatMap function goes here
}

void Flight::showFlightPassengerList()
{
    for (int i = 0; i < passenger_list.size(); i++)
    {
        passenger_list[i].showPassengerInfo();
        cout << "-----------------------------------" << endl;
    }
}