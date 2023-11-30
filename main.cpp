#include <iostream>
#include <string>
#include <vector>

#include "headers/airline.h"
#include "headers/flight.h"
#include "headers/passenger.h"
#include "headers/seat.h"

using namespace std;

// int f(int x) {

//     return x + 1;
// }   


int main(void) {


    Airline airline("WestJet");

    airline.get_airline_name();

    return 0;
}