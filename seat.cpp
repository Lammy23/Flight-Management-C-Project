
#include "headers/seat.h"

Seat::Seat(int rowNum, char colLetter) : rowNumber(rowNum), columnLetter(colLetter), is_occupied(false) {}

Seat::Seat(const Seat &other) : rowNumber(other.rowNumber), columnLetter(other.columnLetter), is_occupied(other.is_occupied) {}
