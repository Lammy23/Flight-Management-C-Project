#ifndef SEAT_H
#define SEAT_H

class Seat
{
private:
    int rowNumber;
    char columnLetter;
    bool status;

public:
    Seat();
    Seat(int rowNum, char colLetter, bool stat);
    Seat(const Seat &other);

    int getRowNumber() const;
    char getColumnLetter() const;
    bool getStatus() const;

    void setRowNumber(int rowNum);
    void setColumnLetter(char colLetter);
    void setStatus(bool stat);
};
#endif // SEAT_H