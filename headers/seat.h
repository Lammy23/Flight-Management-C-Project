#ifndef SEAT_H
#define SEAT_H

class Seat
{
private:
    int rowNumber;
    char columnLetter;
    bool is_occupied;

public:
    Seat() : rowNumber(0), columnLetter(' '), is_occupied(false){}; // Needs work
    Seat(int rowNum, char colLetter);
    Seat(const Seat &other);

    int getRowNumber() const { return rowNumber; };
    char getColumnLetter() const { return columnLetter; }
    bool getStatus() const { return is_occupied; };

    void setRowNumber(int rowNum) { rowNumber = rowNum; };
    void setColumnLetter(char colLetter) { columnLetter = colLetter; };
    void setStatus(bool stat) { is_occupied = stat; };
};
#endif // SEAT_H