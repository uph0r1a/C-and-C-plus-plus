#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Date
{
private:
    int month, day, year;

    string monthName[12] = {"January", "February", "March", "April",
                            "May", "June", "July", "August",
                            "September", "October", "November", "December"};

    int daysInMonth(int m, int y) const
    {
        int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (m == 2 && isLeapYear(y))
            return 29;

        return monthDays[m - 1];
    }

    bool isLeapYear(int y) const
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    bool validDate(int m, int d, int y) const
    {
        if (y < 1 || m < 1 || m > 12 || d < 1)
            return false;

        if (d > daysInMonth(m, y))
            return false;

        return true;
    }

    int toDays() const
    {
        int total = day;

        for (int y = 1; y < year; y++)
            total += isLeapYear(y) ? 366 : 365;

        for (int m = 1; m < month; m++)
            total += daysInMonth(m, year);

        return total;
    }

public:
    Date(int m = 1, int d = 1, int y = 2000)
    {
        if (validDate(m, d, y))
        {
            month = m;
            day = d;
            year = y;
        }
        else
        {
            month = 1;
            day = 1;
            year = 2000;
        }
    }

    Date &operator++()
    {
        day++;

        if (day > daysInMonth(month, year))
        {
            day = 1;
            month++;

            if (month > 12)
            {
                month = 1;
                year++;
            }
        }

        return *this;
    }

    Date operator++(int)
    {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    Date &operator--()
    {
        day--;

        if (day < 1)
        {
            month--;

            if (month < 1)
            {
                month = 12;
                year--;
            }

            day = daysInMonth(month, year);
        }

        return *this;
    }

    Date operator--(int)
    {
        Date temp = *this;
        --(*this);
        return temp;
    }

    int operator-(const Date &other) const
    {
        return abs(this->toDays() - other.toDays());
    }

    friend ostream &operator<<(ostream &out, const Date &obj)
    {
        out << obj.monthName[obj.month - 1] << " "
            << obj.day << ", " << obj.year;
        return out;
    }

    friend istream &operator>>(istream &in, Date &obj)
    {
        int m, d, y;
        char slash1, slash2;

        while (true)
        {
            cout << "Enter date (MM/DD/YYYY): ";
            in >> m >> slash1 >> d >> slash2 >> y;

            if (in.fail() || slash1 != '/' || slash2 != '/')
            {
                in.clear();
                in.ignore(1000, '\n');
                cout << "Invalid format. Try again.\n";
                continue;
            }

            if (obj.validDate(m, d, y))
            {
                obj.month = m;
                obj.day = d;
                obj.year = y;
                break;
            }
            else
            {
                cout << "Invalid date. Try again.\n";
            }
        }

        return in;
    }
};

int main(int argc, char const *argv[])
{
    Date d1, d2;

    cin >> d1;
    cin >> d2;

    cout << "\nFirst Date: " << d1 << endl;
    cout << "Second Date: " << d2 << endl;

    cout << "\nIncrementing first date: " << ++d1 << endl;
    cout << "Postfix increment: " << d1++ << endl;
    cout << "After postfix: " << d1 << endl;

    cout << "\nDecrementing second date: " << --d2 << endl;
    cout << "Postfix decrement: " << d2-- << endl;
    cout << "After postfix: " << d2 << endl;

    cout << "\nDifference in days: " << (d1 - d2) << " days\n";

    return 0;
}