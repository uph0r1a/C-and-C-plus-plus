#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int day, month, year, monthCode[] = {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4}, maxDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (1)
    {
        cout << "Enter the day: ";
        cin >> day;
        cout << "Enter the month: ";
        cin >> month;
        cout << "Enter the year: ";
        cin >> year;
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            maxDay[1] = 29;
        }
        if (month > 0 && month <= 12 && day > 0 && day <= maxDay[month - 1])
        {
            break;
        }
        cout << "This date did not exist\n";
    }

    if (month < 3)
    {
        year -= 1;
    }

    int result = (day + monthCode[month - 1] + ((year % 100) + (year % 100) / 4 + (year / 100) / 4 + 5 * (year / 100)) % 7) % 7;

    switch (result)
    {
    case 0:
        cout << "Sunday";
        break;
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    default:
        break;
    }

    return 0;
}