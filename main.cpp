#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "headers/airline.h"
#include "headers/flight.h"
#include "headers/passenger.h"
#include "headers/seat.h"

using namespace std;

void display_header()
{
    cout << "============================" << endl;
    cout << "Flight Management Program   " << endl;
    cout << "============================" << endl;
    cout << "Version: 1.0                " << endl;
    cout << "============================" << endl;
    cout << "Produced by: Olamikun Aluko " << endl;
    cout << "             Ron Ivan Ibe   " << endl;
    cout << "Year: 2023                  " << endl;
    cout << "============================" << endl;
    cout << "\n<<Press Enter to continue>> ";

    cin.get();
}

void populate_flight_from_file(ifstream &flight_file, Airline &airline)
{

    string airline_info;
    string passenger_info;

    string flight_id, first_name, last_name, phone_number, seat;
    int rows, columns;
    int seatrow;
    char seatcol;
    int passenger_id;

    // Get the first line of the file (flight info)
    getline(flight_file, airline_info);
    istringstream iss(airline_info);

    iss >> flight_id >> rows >> columns;

    // Create a flight object
    Flight flight(flight_id, rows, columns);

    // Get the passenger info
    while (!flight_file.eof())
    {
        getline(flight_file, passenger_info);
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
        istringstream seat_stream(seat);
        seat_stream >> seatrow >> seatcol;

        // Create a passenger object
        Passenger passenger(passenger_id, first_name, last_name, phone_number, flight.getSeat(seatcol, seatrow));

        // Add passenger to flight
        flight.add_passenger(passenger);
    }

    // Add flight to airline
    airline.addFlight(flight);
}

void displayFlightSeatMap(string flight_id, Airline &airline)
{
    airline.getFlight(flight_id).showFlightSeatMap();
    cout << "\n<<Press Enter to continue>> ";
    cin.clear();
    cin.ignore(); // Ignore any remaining characters in the input buffer
    cin.get(); // Wait for the user to press enter
}

void displayPassengerInfo(string flight_id, Airline &airline)
{
    airline.getFlight(flight_id).showInfo();
    cout << "\n<<Press Enter to continue>> ";
    cin.clear();
    cin.get();
}

int menu(Airline &airline)
{
    int input;
    string flight_id;
    cout << "\n\nWelcome to the Flight Management Program!" << endl;
    cout << "Which flight would you like to manage?" << endl;
    airline.showAirlineFlightList();
    cout << "Enter flight ID: ";
    cin >> flight_id;
    cout << endl;


    while (true)
    {
        cout << "\nPlease select one of the following options:" << endl;
        cout << "\n1. Display Flight Seat Map." << endl;
        cout << "\n2. Display Passengers Information." << endl;
        cout << "\n3. Add a new Passenger." << endl;
        cout << "\n4. Remove an Existing Passenger." << endl;
        cout << "\n5. Save data" << endl;
        cout << "\n6. Quit." << endl;
        cout << "\nEnter your choice: (1, 2, 3, 4, 5 or 6) ";
        cin >> input;

        if (cin.fail() || input < 1 || input > 6)
        {
            cin.clear();

            while (cin.get() != '\n')
            {
                continue;
            }

            cout << "Invalid Input\n"
                 << endl;
        }

        else if (input >= 1 && input <= 5)
        {
            switch (input)
            {
            case 1:
                displayFlightSeatMap(flight_id, airline);
                break;
            case 2:
                displayPassengerInfo(flight_id, airline);
                break;
            }
        }

        else
        {
            break;
        }
    }
}

int main(void)
{

    display_header();

    Airline airline("WesJet");

    ifstream flight_file("project-instructions/flight_info.txt");

    if (flight_file.fail())
    {
        cout << "File failed to open" << endl;
        exit(1);
    }

    populate_flight_from_file(flight_file, airline);

    menu(airline);

    return 0;
}