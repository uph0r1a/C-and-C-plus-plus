#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
    class InvalidDay
    {
    };

    class InvalidMonth
    {
    };

    void dateForm(int month, int day, int year)
    {
        if (month < 1 || month > 12)
            throw InvalidMonth();

        if (!validDay(month, day, year))
            throw InvalidDay();

        cout << month << "/" << day << "/" << year << endl
             << monthName[month - 1] << " " << day << ", " << year << endl
             << day << " " << monthName[month - 1] << " " << year << endl;
    }

private:
    string monthName[12] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};

    bool isLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool validDay(int month, int day, int year)
    {
        if (day < 1)
            return false;

        int monthInYear[] = {31, 28, 31, 30, 31, 30,
                             31, 31, 30, 31, 30, 31};

        if (isLeapYear(year) && month == 2)
            monthInYear[1] = 29;

        return day <= monthInYear[month - 1];
    }
};

int main(int argc, char const *argv[])
{

    Date d;
    int month, day, year;

    cout << "Enter month, day, year: ";
    cin >> month >> day >> year;

    try
    {
        d.dateForm(month, day, year);
    }
    catch (Date::InvalidMonth)
    {
        cout << "Error: Invalid month (must be 1 - 12)." << endl;
    }
    catch (Date::InvalidDay)
    {
        cout << "Error: Invalid day for the given month." << endl;
    }

    return 0;
}
