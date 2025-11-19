#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int day, month, year, sum = 0, maxDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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

    for (int i = 0; i < month - 1; i++)
    {
        sum += maxDay[i];
    }

    cout << day << "/" << month << "/" << year << " is the " << sum + day << " days of the year";
    return 0;
}
