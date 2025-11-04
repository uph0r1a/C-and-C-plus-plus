#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int day, month, year;
    cout << "Enter a month: ";
    cin >> month;
    cout << "Enter a day: ";
    cin >> day;
    cout << "Enter a two-digit year: ";
    cin >> year;
    if (day * month == year)
    {
        cout << "The date is magic";
    }
    else
    {
        cout << "The date is not magic";
    }

    return 0;
}
