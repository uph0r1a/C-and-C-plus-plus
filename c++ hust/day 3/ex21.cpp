#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int choice, time;
    cout << "\n__________________________________________________\n"
         << "Select carbon dioxide, air, helium, and hydrogen\n"
         << "1)Carbon Dioxide\n"
         << "2)Air\n"
         << "3)Helium\n"
         <<"4)Hydrogen\n"
         << "Enter a number: ";
loop2:
    cin >> choice;
loop1:
    cout << "Enter the number of seconds it took for the sound to travel in this medium from its source to the location at which it was detected: ";
    cin >> time;
    if (time < 0 || time > 30)
    {
        cout << "Do not accept times less than 0 seconds or more than 30 seconds\n";
        goto loop1;
    }

    switch (choice)
    {
    case 1:
        cout << "The distance (in meters) between the source of the sound and the detection location: "<< (float)time * 258.0  << " m";
        break;
    case 2:
        cout << "The distance (in meters) between the source of the sound and the detection location: " << (float)time * 331.5 << " m";
        break;
    case 3:
        cout << "The distance (in meters) between the source of the sound and the detection location: " << (float)time * 972.0 << " m";
        break;
    case 4:
        cout << "The distance (in meters) between the source of the sound and the detection location: " << (float)time * 1270 << " m";
        break;
    default:
        cout << "Invalid choice\n";
        cout << "Re-enter a number";
        goto loop2;
        break;
    }
    return 0;
}
