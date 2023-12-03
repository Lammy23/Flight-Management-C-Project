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
    Seat &operator=(const Seat &other);

    const int getRowNumber() const { return rowNumber; };
    const char getColumnLetter() const { return columnLetter; }
    const bool getStatus() const { return is_occupied; };

    void setRowNumber(int rowNum) { rowNumber = rowNum; };
    void setColumnLetter(char colLetter) { columnLetter = colLetter; };
    void setStatus(bool stat);
};
#endif // SEAT_H