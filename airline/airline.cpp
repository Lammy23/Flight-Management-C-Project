#include <iostream>
#include <string>
#include <vector>

#include "airline.h"

using namespace std;


Airline::Airline(string airline_name)
{
    this->airline_name = airline_name;
}

Airline::Airline(const Airline &airline)
{
    this->airline_name = airline.airline_name;
    this->flight_list = airline.flight_list;
}

Airline &Airline::operator=(const Airline &airline)
{
    if (this != &airline)
    {
        this->airline_name = airline.airline_name;
        this->flight_list = airline.flight_list;
    }
    return *this;
}

void Airline::add_flight(Flight flight)
{
    flight_list.push_back(flight);
}

void Airline::remove_flight(Flight flight)
{
    if (flight_list.size() == 0)
    {
        cout << "No flights in this airline" << endl;
        return;
    }

    for (int i = 0; i < flight_list.size(); i++)
    {
        if (flight_list[i].get_flight_id() == flight.get_flight_id())
        {
            flight_list.erase(flight_list.begin() + i);
            cout << "Flight removed" << endl;
            return;
        }
    }
    cout << "Flight not found" << endl;
}

void Airline::showAirlineFlightList()
{
    if (flight_list.size() == 0)
    {
        cout << "No flights in this airline" << endl;
        return;
    }

    cout << "Airline: " << airline_name << endl;
    cout << "Flight List: " << endl;
    for (int i = 0; i < flight_list.size(); i++)
    {
        cout << "Flight ID: " << flight_list[i].get_flight_id() << endl;
    }
}

void Airline::showAirlinePassengerList()
{
    if (flight_list.size() == 0)
    {
        cout << "No flights in this airline" << endl;
        return;
    }

    cout << "Airline: " << airline_name << endl;
    cout << "Passenger List: " << endl;
    for (int i = 0; i < flight_list.size(); i++)
    {
        flight_list[i].showFlightPassengerList();
    }
}