#include <iostream>
#include <string>
using namespace std;

int getNumAccidents(string name)
{
    int number_of_accidents;
    cout << "Enter the number of automobile accidents of region " << name << ": ";
    while (1)
    {
        cin >> number_of_accidents;
        if (number_of_accidents >= 0)
        {
            break;
        }
        cout << "The number of automobile accidents cannot be less than 0\nRe-enter the number of automobile accidents of region " << name << ": ";
    }

    return number_of_accidents;
}

void findLowest(int north, int south, int east, int west, int central)
{
    int min = north;
    string region_min = "North";
    if (south < min)
    {
        min = south;
        region_min = "South";
    }
    if (east < min)
    {
        min = east;
        region_min = "East";
    }
    if (south < min)
    {
        min = west;
        region_min = "West";
    }
    if (central < min)
    {
        min = central;
        region_min = "Central";
    }

    cout << "The region with the fewest reported automobile accidents last year: " << region_min << "\nTotal accident: " << min;
}

int main(int argc, char const *argv[])
{
    int north, south, east, west, central;

    north = getNumAccidents("North");
    south = getNumAccidents("South");
    east = getNumAccidents("East");
    west = getNumAccidents("West");
    central = getNumAccidents("Central");

    findLowest(north, south, east, west, central);

    return 0;
}
