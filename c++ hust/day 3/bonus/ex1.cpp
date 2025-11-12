#include <iostream>
using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    int day, month, year;
    bool valid = false;

    while (!valid)
    {
        cout << "Enter the day: ";
        cin >> day;
        cout << "Enter the month: ";
        cin >> month;
        cout << "Enter the year: ";
        cin >> year;

        if (month < 1 || month > 12)
        {
            cout << "The date " << day << "/" << month << "/" << year << " doesn't exist.\n";
            continue;
        }

        int maxDay;
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            maxDay = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxDay = 30;
            break;
        case 2:
            maxDay = isLeapYear(year) ? 29 : 28;
            break;
        }

        if (day >= 1 && day <= maxDay)
        {
            valid = true;
        }
        else
        {
            cout << "The date " << day << "/" << month << "/" << year << " doesn't exist.\n";
        }
    }

    int maxDay;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        maxDay = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDay = 30;
        break;
    case 2:
        maxDay = isLeapYear(year) ? 29 : 28;
        break;
    }

    day++;
    if (day > maxDay)
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }

    cout << "Next day: " << day << "/" << month << "/" << year << endl;
    return 0;
}
