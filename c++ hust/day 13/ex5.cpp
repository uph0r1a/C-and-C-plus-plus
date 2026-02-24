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
    TimeOff(string n, int i, int maxSick, int sick, int maxVac, int vac, int maxNoPaid, int noPaid)
        : name(n),
          id(i),
          maxSickDays(maxSick),
          sickTaken(sick),
          vacTaken(vac),
          maxUnpaid(maxNoPaid),
          unpaidTaken(noPaid)
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
        cout << "Employee name: " << name
             << "\nEmployee ID: " << id
             << "\nMax sick day: " << maxSickDays.getDay()
             << "\nSick taken: " << sickTaken.getDay()
             << "\nMax vacation: " << maxVacation.getDay()
             << "\nVacation taken: " << vacTaken.getDay()
             << "\nMax unpaid: " << maxUnpaid.getDay()
             << "\nUnpaid taken: " << unpaidTaken.getDay();
    }
};

int main(int argc, char const *argv[])
{
    string n;
    int i, maxSick, sick, maxVac, vac, maxNoPaid, noPaid;

    cout << "Enter employee name: ";
    while (1)
    {
        getline(cin, n);
        if (n != "")
        {
            break;
        }
        cout << "Name cannot be empty\nRe-enter employee name: ";
    }

    cout << "Enter employee ID: ";
    cin >> i;

    cout << "Enter employee max sick hours: ";
    while (1)
    {
        cin >> maxSick;
        if (maxSick >= 0)
        {
            break;
        }
        cout << "Number of sick hours cannot be negative\nRe-enter max sick hours: ";
    }

    cout << "Enter employee hours of sick taken: ";
    while (1)
    {
        cin >> sick;
        if (sick >= 0 && sick <= maxSick)
        {
            break;
        }
        cout << "Number of sick hours taken cannot be negative or more than " << maxSick << "\nRe-enter sick hours taken: ";
    }

    cout << "Enter employee max number of hours of paid vacation: ";
    while (1)
    {
        cin >> maxVac;
        if (maxVac >= 0 && maxVac <= 240)
        {
            break;
        }
        cout << "Number of hours of paid vacation cannot be negative or more than 240 hours\nRe-enter max number of hours of paid vacation: ";
    }

    cout << "Enter employee number of hours of paid vacation taken: ";
    while (1)
    {
        cin >> vac;
        if (vac >= 0 && vac <= maxVac)
        {
            break;
        }
        cout << "Number of hours of paid vacation taken cannot be negative or more than " << maxVac << "\nRe-enter number of hours of paid vacation taken: ";
    }

    cout << "Enter employee max number of hours of unpaid vacation: ";
    while (1)
    {
        cin >> maxNoPaid;
        if (maxNoPaid >= 0)
        {
            break;
        }
        cout << "Number of hours of unpaid vacation cannot be negative\nRe-enter max number of hours of unpaid vacation: ";
    }

    cout << "Enter employee number of hours of unpaid vacation taken: ";
    while (1)
    {
        cin >> noPaid;
        if (noPaid >= 0 && noPaid <= maxNoPaid)
        {
            break;
        }
        cout << "Number of hours of unpaid vacation cannot be negative or more than " << maxNoPaid << "\nRe-enter number of hours of unpaid vacation taken: ";
    }

    TimeOff employee(n, i, maxSick, sick, maxVac, vac, maxNoPaid, noPaid);

    employee.display();

    return 0;
}
