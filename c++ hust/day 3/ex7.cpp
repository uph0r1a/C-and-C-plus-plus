#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int second;
    cout << "Enter a number of seconds: ";
    cin >> second;
    if (second >= 60)
    {
        cout << "The number of minutes in " << second << " seconds: " << (float)second / 60;
    }
    else if (second >= 3600)
    {
        cout << "The number of hours in " << second << " seconds: " << (float)second / 3600;
    }
    else if (second >= 86400)
    {
        cout << "The number of days in " << second << " seconds: " << (float)second / 86400;
    }

    return 0;
}
