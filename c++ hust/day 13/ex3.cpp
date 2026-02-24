#include <iostream>
#include <string>
using namespace std;

int dayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string monthStr[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

class DayOfYear
{
private:
    int number;

public:
    DayOfYear(string m, int d)
    {
        number = 0;
        int pos = -1;
        for (int i = 0; i < 12; i++)
        {
            if (m == monthStr[i])
            {
                pos = i;
                break;
            }
        }
        for (int i = 0; i < pos; i++)
        {
            number += dayInMonth[i];
        }
        number += d;
    }

    DayOfYear(int num)
    {
        number = num;
    }

    DayOfYear &operator++()
    {
        ++number;
        if (number > 365)
        {
            number = 1;
        }

        return *this;
    }

    DayOfYear operator++(int)
    {
        DayOfYear temp = *this;
        operator++();
        return temp;
    }

    DayOfYear &operator--()
    {
        --number;
        if (number <= 0)
        {
            number = 365;
        }

        return *this;
    }

    DayOfYear operator--(int)
    {
        DayOfYear temp = *this;
        operator--();
        return temp;
    }

    string print() const
    {
        int temp = number;
        int i = 0;
        while (i < 12 && temp > dayInMonth[i])
        {
            temp -= dayInMonth[i];
            i++;
        }

        return "Day " + to_string(number) + " would be " + monthStr[i] + " " + to_string(temp);
    }
};

int main(int argc, char const *argv[])
{
    int tempDay;
    string tempMonth;
    int pos;

    cout << "Enter the month: ";
    while (1)
    {
        cin >> tempMonth;
        for (int i = 0; i < 12; i++)
        {
            if (tempMonth == monthStr[i])
            {
                pos = i;
                goto enterDay;
            }
        }
        cout << "Month dont exist\nRe-enter month: ";
    }

enterDay:
    cout << "Enter the day: ";
    while (1)
    {
        cin >> tempDay;
        if (tempDay > 0 && tempDay <= dayInMonth[pos])
        {
            break;
        }
        cout << "Day of the year cannot be negative\nRe-enter the day of the year: ";
    }

    DayOfYear day(tempMonth, tempDay);

    cout << (++day).print() + "\n"
         << (day++).print() + "\n"
         << (--day).print() + "\n"
         << (day--).print() + "\n";
    return 0;
}