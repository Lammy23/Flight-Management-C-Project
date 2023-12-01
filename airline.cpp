#include <iostream>
#include <string>
#include <vector>

#include "headers/airline.h"

using namespace std;

Airline::~Airline()
{
    FlightNode *curr = head;
    FlightNode *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

Airline::Airline(const Airline &airline) {
    cout  << "Copy constructor called" << endl;
    airline_name = airline.airline_name;
    num_flights = airline.num_flights;

    FlightNode *curr = airline.head;

    while (curr != nullptr)
    {
        addFlight(curr->flight);
        curr = curr->next;
    }
}

Airline &Airline::operator=(const Airline &airline)
{
    if (this == &airline)
    {
        return *this;
    }

    airline_name = airline.airline_name;
    num_flights = airline.num_flights;

    FlightNode *curr = head;
    FlightNode *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        delete curr;
        curr = next;
    }

    head = nullptr;

    curr = airline.head;

    while (curr != nullptr)
    {
        addFlight(curr->flight);
        curr = curr->next;
    }

    return *this;
}

void Airline::addFlight(Flight &flight)
{
    FlightNode *newNode = new FlightNode(flight);
    newNode->next = head;
    head = newNode;
    num_flights++;
}

void Airline::removeFlight(Flight &flight)
{
    FlightNode *curr = head;
    FlightNode *prev = nullptr;

    while (curr != nullptr && curr->flight != flight)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        return;
    }

    if (prev == nullptr)
    {
        head = head->next;
    }
    else
    {
        prev->next = curr->next;
    }

    delete curr;
    num_flights--;
}

void Airline::showAirlineFlightList()
{
    FlightNode *curr = head;

    while (curr != nullptr)
    {
        cout << curr->flight.get_flight_id() << endl;
        curr = curr->next;
    }
}

Flight &Airline::getFlight(string flight_id)
{
    FlightNode *curr = head;

    while (curr != nullptr && curr->flight.get_flight_id() != flight_id)
    {
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        cout << "Flight not found" << endl;
        static Flight dummy_flight("", 0, 0);
        return dummy_flight;
    }

    return curr->flight;
}

void Airline::showInfo(ostream &stream)
{
    stream << airline_name << endl;
    stream << "Number of flights: " << num_flights << endl;
    cout << endl;

    FlightNode *curr = head;

    while (curr != nullptr)
    {
        curr->flight.showInfo(stream);
        curr = curr->next;
    }
}
