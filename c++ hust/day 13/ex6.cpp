#include <iostream>
#include <string>
using namespace std;

class NumDays
{
private:
    int hour;

public:
    NumDays(int h = 0) : hour(h) {}

    NumDays operator+(NumDays &add) const
    {
        NumDays sum(hour + add.hour);
        return sum;
    }

    NumDays operator-(NumDays &sub) const
    {
        NumDays difference(hour - sub.hour);
        return difference;
    }

    NumDays &operator++()
    {
        ++hour;
        return *this;
    }

    NumDays operator++(int)
    {
        NumDays temp = *this;
        operator++();
        return temp;
    }

    NumDays &operator--()
    {
        --hour;
        return *this;
    }

    NumDays operator--(int)
    {
        NumDays temp = *this;
        operator--();
        return temp;
    }

    float getDay() const
    {
        return hour / 8.0f;
    }
};

class TimeOff
{
private:
    string name;
    int id;
    NumDays maxSickDays, sickTaken, maxVacation, vacTaken, maxUnpaid, unpaidTaken;

public:
    TimeOff(int maxSick, int maxVac)
        : maxSickDays(maxSick)

    {
        if (maxVac > 240)
        {
            maxVacation = 240;
        }
        else
        {
            maxVacation = maxVac;
        }
    }

    void display()
    {
        cout << "Max number of sick leave: " << maxSickDays.getDay()
             << "\nMax number of vacation: " << maxVacation.getDay() << endl;
    }
};

int main(int argc, char const *argv[])
{
    int month;

    cout << "Enter the number of month: ";
    while (1)
    {
        cin >> month;
        if (month >= 0)
        {
            break;
        }
        cout << "Month cannot be negative\nRe-enter the number of month: ";
    }

    TimeOff employee(month * 8, month * 12);

    employee.display();

    return 0;
}
