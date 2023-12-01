#include <string>
#include <iostream>
#include <iomanip>

#include "headers/flight.h"

using namespace std;

Flight::Flight() : flight_id(""), rows(0), columns(0), head(nullptr) {}

Flight::Flight(string flight_id, int rows, int columns) : flight_id(flight_id), rows(rows), columns(columns), head(nullptr)
{

    seat_map.resize(rows, vector<Seat>(columns));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; ++j)
        {
            seat_map[i][j] = Seat(i + 1, (char)'A' + j);
        }
    }
}

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

Seat *Flight::getSeat(char col, int row)
{
    int col_index = (int)col - (int)'A';
    int row_index = row - 1;

    if (col_index < 0 || col_index >= columns || row_index < 0 || row_index >= rows)
    {
        cout << "Invalid seat" << endl;
        return nullptr;
    }

    return &seat_map[row_index][col_index];
}

void Flight::add_passenger(const Passenger passenger)
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

void Flight::showInfo()
{
    PassengerNode *curr = head;

    cout << setw(20) << left << "First Name" << setw(20) << left << "Last Name" << setw(20) << left << "Phone Number" << setw(5) << left << "Row" << setw(5) << left << "Seat" << setw(10) << left << "ID" << endl;
    
    for (int i = 0; i < 80; ++i)
    {
        cout << "-";
    }
    cout << endl;

    while (curr != nullptr)
    {
        curr->passenger.showInfo();
        for (int i = 0; i < 80; ++i)
        {
            cout << "-";
        }
        cout << endl;

        // cout << curr->passenger.getFirstName() << " " << curr->passenger.getLastName() << endl;
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
            cout << "| " << (seat_map[i][j].getStatus() == false ? ' ' : 'X') << " ";
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