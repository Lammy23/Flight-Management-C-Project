#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include <vector>

#include "flight.h"

using namespace std;

class Airline {
private:
    string airline_name;
    vector<Flight> flight_list;

public:
    Airline(string airline_name);
    ~Airline(){};
    Airline(const Airline &airline);
    Airline &operator=(const Airline &airline);

    const string get_airline_name() const { return airline_name; };

    void set_airline_name(string airline_name) { this->airline_name = airline_name; };

    void add_flight(Flight flight);
    void remove_flight(Flight flight);

    void showAirlineFlightList();
    void showAirlinePassengerList();
};

#endif // AIRLINE_H