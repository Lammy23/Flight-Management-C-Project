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
    Flight* flight = new Flight(flight_id, rows, columns);

    // Get the passenger info
    while (getline(flight_file, passenger_info))
    {
        // getline(flight_file, passenger_info);
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
        Seat *flight_seat = (*flight).getSeat(seatcol, seatrow);

        // Create a passenger object
        Passenger passenger(passenger_id, first_name, last_name, phone_number, flight_seat);

        // Add passenger to flight
        (*flight).add_passenger(passenger);
    }

    // Add flight to airline
    airline.addFlight(*flight);
    flight_file.close();
}

void changeFlight(string &flight_id, Airline &airline)
{
    cout << "Which flight would you like to manage?" << endl;
    airline.showAirlineFlightList();
    cout << "Enter flight ID: ";
    cin >> flight_id;
    cout << endl;
    cout << "Flight changed successfully" << endl;
    cout << "\n<<Press any key to continue>> ";
    cin.clear();
    cin.ignore();
    cin.get();
}

void displayFlightSeatMap(string &flight_id, Airline &airline)
{
    airline.getFlight(flight_id).showFlightSeatMap();
    cout << "\n<<Press any key to continue>> ";
    cin.clear();
    cin.ignore();
    cin.get();
}

void displayPassengerInfo(string &flight_id, Airline &airline)
{
    airline.getFlight(flight_id).showInfo();
    cout << "\n<<Press any key to continue>> ";
    cin.clear();
    cin.ignore();
    cin.get();
}

void addNewPassenger(string &flight_id, Airline &airline)
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

void removePassenger(string &flight_id, Airline &airline)
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

void saveData(string &flight_id, Airline &airline)
{
    string file_name;
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

void addFlightFromFile(Airline &airline)
{
    string file_name;
    cout << "Enter the file name: ";
    cin >> file_name;

    ifstream flight_file(file_name);

    if (flight_file.fail())
    {
        cout << "File failed to open" << endl;
        return;
    }

    populate_flight_from_file(flight_file, airline);
    cout << "Flight added successfully" << endl;
    cout << "\n<<Press any key to continue>> ";
    cin.clear();
    cin.ignore();
    cin.get();
}

void menu(string airline_name = "WesJet")
{
    Airline airline(airline_name);
    // Open flight file
    ifstream flight_file("flight_info.txt");

    // Check if file opened successfully
    if (flight_file.fail())
    {
        cout << "File failed to open" << endl;
        exit(1);
    }

    // Populate airline with flights from file
    populate_flight_from_file(flight_file, airline);

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
        cout << "\n1. Change Flight." << endl;
        cout << "\n2. Display Flight Seat Map." << endl;
        cout << "\n3. Display Passengers Information." << endl;
        cout << "\n4. Add a new Passenger." << endl;
        cout << "\n5. Remove an Existing Passenger." << endl;
        cout << "\n6. Save data to file" << endl;
        cout << "\n7. Add a new Flight from file." << endl;
        cout << "\n8. Quit." << endl;
        cout << "\nEnter your choice: (1, 2, 3, 4, 5, 6, 7, or 8) ";
        cin >> input;

        if (cin.fail() || input < 1 || input > 8)
        {
            cin.clear();

            while (cin.get() != '\n')
            {
                continue;
            }

            cout << "Invalid Input\n"
                 << endl;
        }

        else if (input >= 1 && input <= 7)
        {
            switch (input)
            {
            case 1:
                changeFlight(flight_id, airline);
                break;
            case 2:
                displayFlightSeatMap(flight_id, airline);
                break;
            case 3:
                displayPassengerInfo(flight_id, airline);
                break;
            case 4:
                addNewPassenger(flight_id, airline);
                break;
            case 5:
                removePassenger(flight_id, airline);
                break;
            case 6:
                saveData(flight_id, airline);
                break;

            case 7:
                addFlightFromFile(airline);
                break;
            }
        }

        else
        {
            break;
        }
    }
    flight_file.close();
    return;
}

int main(void)
{

    display_header();

    // Display menu for WesJet
    menu("WesJet");

    return 0;
}