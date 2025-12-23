#include <iostream>
#include <vector>
using namespace std;

bool isLeapYear(string year)
{
    return ((stoi(year) % 400 == 0) || (stoi(year) % 4 == 0 && stoi(year) % 100 != 0));
}

int main(int argc, char const *argv[])
{
    string day, month, year, date;
    int jump = 0;

    cout << "Enter a date(mm/dd/yyyy): ";
    cin >> date;

    for (char c : date)
    {

        if (c == '/')
        {
            jump++;
            continue;
        }

        if (jump == 0)
        {
            month += c;
        }
        else if (jump == 1)
        {
            day += c;
        }
        else
        {
            year += c;
        }
    }

    int monthNumber = stoi(month);

    vector<string> monthNames = {"January", "February", "March", "April", "May", "June",
                                 "July", "August", "September", "October", "November", "December"};

    if (monthNumber >= 1 && monthNumber <= 12)
    {
        month = monthNames[monthNumber - 1];
    }
    else
    {
        cout << "Invalid month" << endl;
        return 1;
    }

    switch (monthNumber)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (stoi(day) < 1 || stoi(day) > 31)
        {
            cout << "Invalid date" << endl;
            return 1;
        }
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        if (stoi(day) < 1 || stoi(day) > 30)
        {
            cout << "Invalid date" << endl;
            return 1;
        }
        break;

    case 2:
        if (((stoi(day) < 1 || stoi(day) > 29) && isLeapYear(year)) || ((stoi(day) < 1 || stoi(day) > 28) && !isLeapYear(year)))
        {
            cout << "Invalid date" << endl;
            return 1;
        }
        break;
    default:
        break;
    }

    cout << month << " " << day << ", " << year << endl;

    return 0;
}
