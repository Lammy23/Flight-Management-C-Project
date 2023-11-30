#ifndef SEAT_H
#define SEAT_H

class Seat
{
private:
    int rowNumber;
    char columnLetter;
    bool status;

public:
    Seat(int rowNum, char colLetter, bool stat);
    Seat(const Seat &other);
    ~Seat() {}
    int getRowNumber() const { return rowNumber; }
    char getColumnLetter() const { return columnLetter; }
    bool getStatus() const { return status; }
    void setRowNumber(int rowNum) { rowNumber = rowNum; }
    void setColumnLetter(char colLetter) { columnLetter = colLetter; }
    void setStatus(bool stat) { status = stat; }
};

#endif // SEAT_H