#include <string>
#include <iostream>
#include <iomanip>

#include "headers/flight.h"

using namespace std;

Flight::~Flight()
{
    PassengerNode *curr = head;
    PassengerNode *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

Flight::Flight(const Flight &flight)
{
    flight_id = flight.flight_id;
    rows = flight.rows;
    columns = flight.columns;
    head = nullptr;
    seat_map = flight.seat_map;

    PassengerNode *curr = flight.head;

    while (curr != nullptr)
    {
        add_passenger(curr->passenger);
        curr = curr->next;
    }
}

Flight &Flight::operator=(const Flight &flight)
{
    if (this == &flight)
    {
        return *this;
    }

    flight_id = flight.flight_id;
    rows = flight.rows;
    columns = flight.columns;
    seat_map = flight.seat_map;

    PassengerNode *curr = head;
    PassengerNode *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        delete curr;
        curr = next;
    }

    head = nullptr;

    curr = flight.head;

    while (curr != nullptr)
    {
        add_passenger(curr->passenger);
        curr = curr->next;
    }

    return *this;
}

Passenger Flight::getPassenger(int passenger_id)
{
    PassengerNode *curr = head;

    while (curr != nullptr)
    {
        if (curr->passenger.getPassengerID() == passenger_id)
        {
            return curr->passenger;
        }

        curr = curr->next;
    }

    return Passenger();
}

string *Flight::getSeat(int row, int column)
{
    return &seat_map[row][column];
}

void Flight::add_passenger(Passenger passenger)
{
    PassengerNode *newNode = new PassengerNode(passenger);
    newNode->next = head;
    head = newNode;
}

void Flight::remove_passenger(Passenger passenger)
{
    PassengerNode *curr = head;
    PassengerNode *prev = nullptr;

    while (curr != nullptr)
    {
        if (curr->passenger == passenger)
        {
            if (prev == nullptr)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }

            delete curr;
            break;
        }

        prev = curr;
        curr = curr->next;
    }
}

void Flight::showFlightPassengerList()
{
    PassengerNode *curr = head;

    while (curr != nullptr)
    {
        cout << curr->passenger.getFirstName() << " " << curr->passenger.getLastName() << endl;
        curr = curr->next;
    }
}

void Flight::showFlightSeatMap()
{

    cout << "\tAircraft Seat Map\n";
    cout << "     ";

    for (int i = 0; i < columns; ++i)
    {
        cout << (char)('A' + i) << "   ";
    }

    cout << "\n   ";

    for (int k = 0; k < columns; ++k)
    {
        cout << "+---";
    }
    cout << "+\n";

    for (int i = 0; i < rows; ++i)
    {
        cout << setw(2) << i + 1 << " ";
        for (int j = 0; j < columns; ++j)
        {
            cout << "| " << (seat_map[i][j] == " " ? ' ' : 'X') << " ";
        }
        cout << "|\n   ";

        for (int k = 0; k < columns; ++k)
        {
            cout << "+---";
        }
        cout << "+\n";
    }
}

ostream &operator<<(ostream &os, const Flight &flight)
{
    os << "Flight ID: " << flight.get_flight_id() << endl;
    os << "Rows: " << flight.get_rows() << endl;
    os << "Columns: " << flight.get_columns() << endl;

    return os;
}