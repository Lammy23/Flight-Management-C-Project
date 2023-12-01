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
    cout << "\n<<Press any key to continue>> ";
    cin.clear();
    cin.ignore();
    cin.get();
}

void displayPassengerInfo(string flight_id, Airline &airline)
{
    airline.getFlight(flight_id).showInfo();
    cout << "\n<<Press any key to continue>> ";
    cin.clear();
    cin.ignore();
    cin.get();
}

void addNewPassenger(string flight_id, Airline &airline)
{
    Flight &flight = airline.getFlight(flight_id);
    int id, row;
    string firstName, lastName, phoneNumber;
    char seat;

    cout << "Please enter the passenger ID: ";
    cin >> id;

    cout << "Please enter the passenger first name: ";
    getline(cin >> ws, firstName);

    cout << "Please enter the passenger last name: ";
    getline(cin >> ws, lastName);

    cout << "Please enter the passenger phone number: ";
    cin >> phoneNumber;

    cout << "Enter the passenger's desired row: ";
    cin >> row;

    cout << "Enter the passenger's desired seat: ";
    cin >> seat;

    Passenger passenger(id, firstName, lastName, phoneNumber, flight.getSeat(seat, row));
    airline.getFlight(flight_id).add_passenger(passenger);
    cout << "Here is the passenger's information:" << endl;
    airline.getFlight(flight_id).getPassenger(id).showInfo();

    cout << "\n<<Press any key to continue>> ";
    cin.clear();
    cin.ignore();
    cin.get();
}

void removePassenger(string flight_id, Airline &airline)
{
    int passengerID;
    cout << "\nEnter the id of the passenger that needs to be removed: ";
    cin >> passengerID;

    if (airline.getFlight(flight_id).getPassenger(passengerID).getPassengerID() == -1)
    {
        cout << "Passenger not found" << endl;
        return;
    }

    airline.getFlight(flight_id).remove_passenger(airline.getFlight(flight_id).getPassenger(passengerID));

    cout << "Passenger removed successfully" << endl;
    cout << "\n<<Press any key to continue>> ";
    cin.clear();
    cin.ignore();
    cin.get();
}

void saveData(string flight_id, Airline &airline)
{
    string file_name;
    Flight &flight = airline.getFlight(flight_id);
    cout << "Where would you like to save the data? (Enter the file name):";
    cin >> file_name;

    ofstream flight_file(file_name);

    if (flight_file.fail())
    {
        cout << "File failed to open" << endl;
        exit(1);
    }

    airline.showInfo(flight_file);

    flight_file.close();
    cout << "Data saved successfully" << endl;
    cout << "\n<<Press any key to continue>> ";
    cin.clear();
    cin.ignore();
    cin.get();
}

void menu(Airline &airline)
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
            case 3:
                addNewPassenger(flight_id, airline);
                break;
            case 4:
                removePassenger(flight_id, airline);
                break;
            case 5:
                saveData(flight_id, airline);
                break;
            }
        }

        else
        {
            break;
        }
    }

    return;
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