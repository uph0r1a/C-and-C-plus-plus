#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float starting_time, number_of_minute;

loop1:
    cout << "Enter the starting time: ";
    cin >> starting_time;
    if ((starting_time - static_cast<int>(starting_time)) * 10 > 59 || (starting_time - static_cast<int>(starting_time)) * 10 < 0 || static_cast<int>(starting_time) < 0 || static_cast<int>(starting_time) > 23)
    {
        cout << "The program dont accept times that are greater than 23:59 or lower than 00:00";
        goto loop1;
    }

    cout << "Enter the number of minutes of the call: ";
    cin >> number_of_minute;

    if (starting_time >= 0 && starting_time <= 6.59)
    {
        cout << "The charges: " << number_of_minute * 0.05;
    }
    else if (starting_time >= 7 && starting_time <= 19)
    {
        cout << "The charges: " << number_of_minute * 0.45;
    }
    else
    {
        cout << "The charges: " << number_of_minute * 0.2;
    }

    return 0;
}