#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int floor, room, occupied, total_room = 0, total_occupied = 0;

    cout << "Enter the number of floors the hotel has: ";
    while (1)
    {
        cin >> floor;
        if (floor < 1)
        {
            break;
        }
        cout << "Do not accept a value less than 1 for the number of floors";
        cout << "Re-enter the number of floors the hotel has: ";
    }

    for (int i = 1; i <= floor; i++)
    {
        if (i == 13)
        {
            continue;
        }
        cout << "Enter the number of rooms on floor " << i << ": ";
        while (1)
        {
            cin >> room;
            if (room < 10)
            {
                break;
            }
            cout << "Do not accept a number less than 10 for the number of rooms on a floor\n";
            cout << "Re-enter the number of rooms on floor " << i << ": ";
        }

        total_room += room;
        cout << "Enter how many of them are occupied: ";
        cin >> occupied;
        total_occupied += occupied;
    }

    cout << "The number of rooms the hotel has: " << total_room << "\n"
         << "The number of rooms that are occupied: " << total_occupied << "\n"
         << "The number of rooms that are unoccupied: " << total_room - total_occupied << "\n"
         << "Percentage of rooms that are occupied: " << (static_cast<float>(total_occupied / total_room)) * 100 << "%";

    return 0;
}
