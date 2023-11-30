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

Airline::Airline(const Airline &airline)
{
    airline_name = airline.airline_name;
    head = nullptr;

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

void Airline::addFlight(Flight flight)
{
    FlightNode *newNode = new FlightNode(flight);
    newNode->next = head;
    head = newNode;
}

void Airline::removeFlight(Flight flight)
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

Flight Airline::findFlight(string flight_id)
{
    FlightNode *curr = head;

    while (curr != nullptr && curr->flight.get_flight_id() != flight_id)
    {
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        return Flight("", 0, 0);
    }

    return curr->flight;
}
