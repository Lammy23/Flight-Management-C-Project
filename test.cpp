#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;

int main(void)
{

    string airline_info;
    string passenger_info;

    string flight_id;
    int rows, cols;

    string first_name, last_name, phone_number, seat;
    int row;
    char col;
    int passenger_id;

    ifstream file("project-instructions/flight_info.txt");

    if (file.fail())
    {
        cout << "File failed to open" << endl;
        exit(1);
    }

    getline(file, airline_info);
    istringstream iss(airline_info);

    iss >> flight_id >> rows >> cols;

    cout << "Flight ID: " << flight_id << endl;
    cout << "Rows: " << rows << endl;
    cout << "Cols: " << cols << endl;

    while (!file.eof())
    {
        getline(file, passenger_info);
        // Extract passenger information
        istringstream iss(passenger_info);
        string field;

        iss >> first_name;
        iss.seekg(1, ios::cur); // Skip space

        if (iss.peek() != ' ')
        {
            string temp;
            iss >> temp;
            first_name += " " + temp;
        }

        iss >> last_name;
        iss.seekg(1, ios::cur); // Skip space

        if (iss.peek() != ' ')
        {
            string temp;
            iss >> temp;
            last_name += " " + temp;
        }

        iss >> phone_number >> seat >> passenger_id;

        // Split seat into row and column
        istringstream iss2(seat);

        iss2 >> row >> col;

        // NEW AGENDA: SPLIT SEAT INTO ROW AND COLUMN

        cout << "First Name: " << first_name << "  ";
        cout << "Last Name: " << last_name << "  ";
        cout << "Phone Number: " << phone_number << "  ";
        cout << "Seat: " << seat << "  ";
        cout << "Seat row: " << row << "  ";
        cout << "Seat col: " << col << "  ";
        cout << "Passenger ID: " << passenger_id << "  ";
        cout << "\n\n";
    }

    file.close();

    return 0;
}// void populate_flight_from_file(ifstream &flight_file, Airline &airline)
// {

//     string airline_info;
//     string passenger_info;

//     string flight_id, first_name, last_name, phone_number, seat;
//     int rows, columns;
//     int seatrow;
//     char seatcol;
//     int passenger_id;

//     // Get the first line of the file (flight info)
//     getline(flight_file, airline_info);
//     istringstream iss(airline_info);

//     iss >> flight_id >> rows >> columns;

//     // Create a flight object
//     Flight flight(flight_id, rows, columns);

//     // Get the passenger info
//     while (getline(flight_file, passenger_info))
//     {
//         // getline(flight_file, passenger_info);
//         // Extract passenger information
//         istringstream iss(passenger_info);
//         string field;

//         iss >> first_name;
//         iss.seekg(1, ios::cur); // Skip space

//         if (iss.peek() != ' ')
//         {
//             string temp;
//             iss >> temp;
//             first_name += " " + temp;
//         }

//         iss >> last_name;
//         iss.seekg(1, ios::cur); // Skip space

//         if (iss.peek() != ' ')
//         {
//             string temp;
//             iss >> temp;
//             last_name += " " + temp;
//         }

//         iss >> phone_number >> seat >> passenger_id;

//         // Split seat into row and column
//         istringstream seat_stream(seat);
//         seat_stream >> seatrow >> seatcol;
//         Seat *flight_seat = flight.getSeat(seatcol, seatrow);

//         // Create a passenger object
//         Passenger passenger(passenger_id, first_name, last_name, phone_number, flight_seat);

//         // Add passenger to flight
//         flight.add_passenger(passenger);
//     }

//     // Add flight to airline
//     airline.addFlight(flight);
//     flight_file.close();
// }
