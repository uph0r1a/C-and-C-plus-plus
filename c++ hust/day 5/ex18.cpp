#include <iostream>
using namespace std;

void Paint()
{
    int number_of_room;
    float price_per_gallon, wall_space_per_room;

    cout << "Enter the number of room: ";
    while (1)
    {
        cin >> number_of_room;
        if (number_of_room >= 1)
        {
            break;
        }
        cout << "Number of room cannot be less than 1\nRe-enter the number of room: ";
    }

    cout << "Enter the price per gallon: ";
    while (1)
    {
        cin >> price_per_gallon;
        if (price_per_gallon >= 10)
        {
            break;
        }
        cout << "Price per gallon cannot be less than 10\nRe-enter the price per gallon: ";
    }

    cout << "Enter the wall space per room: ";
    while (1)
    {
        cin >> wall_space_per_room;
        if (wall_space_per_room >= 0)
        {
            break;
        }
        cout << "Wall space per room cannot be less than 0\nRe-enter the wall space per room: ";
    }

    cout << "The number of gallons of paint required: " << (wall_space_per_room * static_cast<float>(number_of_room)) / 110 << "\nThe hours of labor required: " << ((wall_space_per_room * static_cast<float>(number_of_room)) / 110) * 8 << "\nThe cost of the paint: " << ((wall_space_per_room * static_cast<float>(number_of_room)) / 110) * price_per_gallon << "\nThe labor charges: " << (((wall_space_per_room * static_cast<float>(number_of_room)) / 110) * 8) * 25 << "\nThe total cost of the paint job: " << (((wall_space_per_room * static_cast<float>(number_of_room)) / 110) * price_per_gallon) + ((((wall_space_per_room * static_cast<float>(number_of_room)) / 110) * 8) * 25);
}

int main(int argc, char const *argv[])
{
    Paint();
    return 0;
}
