#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>

#include "passenger.h"

typedef vector<vector<Seat>> SeatMap;

class PassengerNode
{
public:
    Passenger passenger;
    PassengerNode *next;

    PassengerNode() : passenger(), next(nullptr) {}
    PassengerNode(Passenger passenger, PassengerNode *next = nullptr) : passenger(passenger), next(next) {}
};

class Flight
{
private:
    string flight_id;
    int rows;
    int columns;
    PassengerNode *head;
    SeatMap seat_map;

public:
    Flight();
    Flight(string flight_id, int rows, int columns);

    ~Flight();
    Flight(const Flight &flight);
    Flight &operator=(const Flight &flight);
    bool operator==(const Flight &flight) const { return flight_id == flight.flight_id; };
    bool operator!=(const Flight &flight) const { return flight_id != flight.flight_id; };

    const string get_flight_id() const { return flight_id; };
    const int get_rows() const { return rows; };
    const int get_columns() const { return columns; };
    Passenger &getPassenger(int passenger_id);
    Seat *getSeat(char col, int row);

    void set_flight_id(string flight_id) { this->flight_id = flight_id; };
    void set_rows(int rows) { this->rows = rows; };
    void set_columns(int columns) { this->columns = columns; };

    void add_passenger(Passenger &passenger);
    void remove_passenger(Passenger &passenger);
    int count_passengers();

    void showFlightSeatMap();
    void showInfo(ostream &stream = cout);
};

#endif // FLIGHT_H