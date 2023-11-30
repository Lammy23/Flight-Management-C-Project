#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>

#include "flight.h"

using namespace std;

class FlightNode
{
public:
    Flight flight;
    FlightNode *next;

    FlightNode(Flight flight, FlightNode *next = nullptr) : flight(flight), next(next) {}
};

class Airline
{
private:
    string airline_name;
    FlightNode *head;

public:
    Airline(string airline_name) : airline_name(airline_name), head(nullptr) {}
    ~Airline();
    Airline(const Airline &airline);
    Airline &operator=(const Airline &airline);

    void set_airline_name(string airline_name) { this->airline_name = airline_name; };
    const string get_airline_name() const { return airline_name; };

    void addFlight(Flight flight);
    void removeFlight(Flight flight);
    Flight findFlight(string flight_id);
    void showAirlineFlightList();
};

#endif // AIRLINE_H