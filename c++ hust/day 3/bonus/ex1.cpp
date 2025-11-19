#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int day, month, year, maxDay;
loop:
    cout << "Enter the day: ";
    cin >> day;
    cout << "Enter the month: ";
    cin >> month;
    cout << "Enter the year: ";
    cin >> year;

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
        if (day <= 0 || day > maxDay)
        {
            cout << "This date didnt exist\n";
            goto loop;
        }
        if (day == maxDay && month == 12)
        {
            day = 1;
            month = 1;
            year++;
        }
        else if (day == maxDay)
        {
            day = 1;
            month++;
        }
        else
        {
            day++;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDay = 30;
        if (day <= 0 || day > maxDay)
        {
            cout << "This date didnt exist\n";
            goto loop;
        }
        if (day == maxDay)
        {
            day = 1;
            month++;
        }
        else
        {
            day++;
        }

        break;
    case 2:
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            maxDay = 29;
        }
        else
        {
            maxDay = 28;
        }

        if (day <= 0 || day > maxDay)
        {
            cout << "This date didnt exist\n";
            goto loop;
        }
        if (day == maxDay)
        {
            day = 1;
            month++;
        }
        else
        {
            day++;
        }
        break;

    default:
        cout << "This date didnt exist\n";
        goto loop;
        break;
    }

    cout << "Next day: " << day << "/" << month << "/" << year;

    return 0;
}
