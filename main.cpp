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

    cout << "\nVersion: 1.0" << endl;
    cout << "\nTerm Project - Flight Mannagement Program in C++" << endl;
    cout << "\nProduced by: Ron Ivan Ibe, Olamikun Aluko" << endl;
    cout << "\nYear: 2023" << endl;
    cout << "\n<<Press Enter to continue>> ";

    cin.get();
}

int menu()
{

    int input;

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
        else
        {
            exit(1);
        }
    }
}

void populate_flight_from_file(ifstream &flight_file, Airline &airline) {


}

int main(void)
{

    Airline airline("WestJet");
    cout << airline.get_num_flights() << endl;

    airline.addFlight(Flight("WS100", 10, 6));
    airline.addFlight(Flight("WS200", 10, 6));
    airline.addFlight(Flight("WS300", 10, 6));

    Flight first_flight = airline.getFlight("WS100");

    first_flight.add_passenger(Passenger(10001, "Ron", "Ibe", "1234567890", first_flight.getSeat(1, 1)));
    first_flight.add_passenger(Passenger(10002, "Olamikun", "Aluko", "1234567890", first_flight.getSeat(1, 2)));

    first_flight.showFlightPassengerList();
    first_flight.showFlightSeatMap();

    return 0;
}