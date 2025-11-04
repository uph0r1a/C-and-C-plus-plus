#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int pennies, nickels, dimes, quarters;
    cout << "Enter the number of pennies: ";
    cin >> pennies;
    cout << "Enter the number of nickels: ";
    cin >> nickels;
    cout << "Enter the number of dimes: ";
    cin >> dimes;
    cout << "Enter the number of quarters: ";
    cin >> quarters;

    if (pennies * 0.01 + nickels * 0.05 + dimes * 0.1 + quarters * 0.25 == 1)
    {
        cout << "Congratulate user for winning the game";
    }
    else if (pennies * 0.01 + nickels * 0.05 + dimes * 0.1 + quarters * 0.25 >= 1)
    {
        cout << "The amount entered was more than one dollar";
    }
    else
    {
        cout << "The amount entered was less than one dollar";
    }

    return 0;
}
