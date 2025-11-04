#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int month, year;

    cout << "Enter a year: ";
    cin >> year;
loop:
    cout << "Enter a month (1-12): ";
    cin >> month;

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << 31 << "days";
        break;
    case 2:
        if (year % 100 == 0 && year % 400 == 0 || year % 4 == 0)
        {
            cout << 29 << "days";
        }
        else
        {
            cout << 28 << "days";
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout << 30 << "days";
        break;
    default:
        cout << "Month must be in the range of 1 through 12";
        goto loop;
        break;
    }

    return 0;
}
