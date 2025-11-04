#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int choice;
    float distance;
    cout << "\n_____________________________\n"
         << "Select air, water, or steel\n"
         << "1)Air\n"
         << "2)Water\n"
         << "3)Steel\n"
         << "Enter a number: ";
loop2:
    cin >> choice;
loop1:
    cout << "Enter the distance a sound wave will travel in the selected medium: ";
    cin >> distance;
    if (distance < 0)
    {
        cout << "Do not accept distances less than 0\n";
        goto loop1;
    }

    switch (choice)
    {
    case 1:
        cout << "The amount of time it will take: " << fixed << setprecision(4) << distance / 1100 << " second";
        break;
    case 2:
        cout << "The amount of time it will take: " << fixed << setprecision(4) << distance / 4900 << " second";
        break;
    case 3:
        cout << "The amount of time it will take: " << fixed << setprecision(4) << distance / 16400 << " second";
        break;
    default:
        cout << "Invalid choice\n";
        cout << "Re-enter a number";
        goto loop2;
        break;
    }
    return 0;
}
