#include <string>
#include <vector>

#include "passenger/passenger.h"

class Flight
{

private:
    string flight_id;
    int rows;
    int columns;
    vector<Passenger> passenger_list;
    vector<vector<string>> seat_map;

public:
    Flight(string flight_id, int rows, int columns);
    ~Flight(){};
    Flight(const Flight &flight);
    Flight &operator=(const Flight &flight);

    const string get_flight_id() const { return flight_id; };
    const int get_rows() const { return rows; };
    const int get_columns() const { return columns; };

    void set_flight_id(string flight_id) { this->flight_id = flight_id; };
    void set_rows(int rows) { this->rows = rows; };
    void set_columns(int columns) { this->columns = columns; };

    void add_passenger(Passenger passenger);
    void remove_passenger(Passenger passenger);

    void showFlightSeatMap();
    void showFlightPassengerList();
};