#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
    void dateForm(int month, int day, int year)
    {
        if (validDate(month, day, year))
        {
            cout << month << "/" << day << "/" << year << endl
                 << monthName[month - 1] << " " << day << ", " << year << endl
                 << day << " " << monthName[month - 1] << " " << year << endl;
        }
        else
        {
            cout << "Invalid date" << endl;
        }
    }

private:
    int month, day, year;
    string monthName[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    bool isLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool validDate(int month, int day, int year)
    {
        if (day < 1 || month < 1 || month > 12 || year < 1)
        {
            return false;
        }

        int monthInYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (isLeapYear(year) && month == 2)
        {
            monthInYear[1] = 29;
        }

        return day <= monthInYear[month - 1];
    }
};

int main(int argc, char const *argv[])
{
    int month, day, year;
    Date d;

    cout << "Enter the month: ";
    cin >> month;

    cout << "Enter the day: ";
    cin >> day;

    cout << "Enter the year: ";
    cin >> year;

    d.dateForm(month, day, year);

    return 0;
}
