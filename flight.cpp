#include <string>
#include <iostream>

#include "headers/flight.h"

using namespace std;

Flight::~Flight() {
    PassengerNode* curr = head;
    PassengerNode* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

Flight::Flight(const Flight &flight) {
    flight_id = flight.flight_id;
    rows = flight.rows;
    columns = flight.columns;
    head = nullptr;

    PassengerNode* curr = flight.head;

    while (curr != nullptr) {
        add_passenger(curr->passenger);
        curr = curr->next;
    }
}

Flight &Flight::operator=(const Flight &flight) {
    if (this == &flight) {
        return *this;
    }

    flight_id = flight.flight_id;
    rows = flight.rows;
    columns = flight.columns;

    PassengerNode* curr = head;
    PassengerNode* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }

    head = nullptr;

    curr = flight.head;

    while (curr != nullptr) {
        add_passenger(curr->passenger);
        curr = curr->next;
    }

    return *this;
}

void Flight::showFlightPassengerList() {
    PassengerNode* curr = head;

    while (curr != nullptr) {
        // cout << curr->passenger.get_first_name() << " " << curr->passenger.get_last_name() << endl;
        curr = curr->next;
    }
}

void Flight::showFlightSeatMap() {
    vector<vector<char>> seat_map(rows, vector<char>(columns, 'O'));

    PassengerNode* curr = head;

    while (curr != nullptr) {
        // seat_map[curr->passenger.get_seat().get_row() - 1][curr->passenger.get_seat().get_column() - 1] = 'X';
        curr = curr->next;
    }

    cout << "  ";

    for (int i = 0; i < columns; i++) {
        cout << i + 1 << " ";
    }

    cout << endl;

    for (int i = 0; i < rows; i++) {
        cout << i + 1 << " ";

        for (int j = 0; j < columns; j++) {
            cout << seat_map[i][j] << " ";
        }

        cout << endl;
    }
}

ostream &operator<<(ostream &os, const Flight &flight) {
    os << "Flight ID: " << flight.get_flight_id() << endl;
    os << "Rows: " << flight.get_rows() << endl;
    os << "Columns: " << flight.get_columns() << endl;

    return os;
}