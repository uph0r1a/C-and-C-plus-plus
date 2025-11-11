#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int time;
    float speed;
    while (1)
    {
        cout << "Enter the speed of a vehicle (in miles per hour): ";
        cin >> speed;
        cout << "Enter how many hours it has traveled: ";
        cin >> time;

        if (speed > 0 && time > 1)
        {
            break;
        }
        cout << "Do not accept a negative number for speed and do not accept any value less than 1 for time traveled\n";
    }

    cout << "Hour\tDistance Traveled\n";
    cout << "-------------------------------------------------------\n";

    for (int i = 1; i <= time; i++)
    {
        cout << i << setw(10) << speed * i << "\n";
    }

    return 0;
}
