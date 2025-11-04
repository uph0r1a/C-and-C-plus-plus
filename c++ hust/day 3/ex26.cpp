#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

int main()
{
    char package;
    float minutes, total;

    while (true)
    {
        cout << "Enter the package purchased (A, B, or C): ";
        cin >> package;
        package = toupper(package);

        if (package == 'A' || package == 'B' || package == 'C')
            break;
        cout << "Invalid input. Please enter A, B, or C.\n";
    }

    cout << "Enter the number of minutes used: ";
    cin >> minutes;

    if (package == 'A')
    {
        total = 39.99;
        if (minutes > 450)
            total += (minutes - 450) * 0.45;
    }
    else if (package == 'B')
    {
        total = 59.99;
        if (minutes > 900)
            total += (minutes - 900) * 0.40;
    }
    else if (package == 'C')
    {
        total = 69.99;
    }

    cout << "\nThe total amount due: $" << total << endl;

    if (package == 'A')
    {
        double costB = 59.99;
        if (minutes > 900)
            costB += (minutes - 900) * 0.40;

        double costC = 69.99;

        if (costB < total)
            cout << "If you purchased Package B, you would save $" << total - costB << endl;

        if (costC < total)
            cout << "If you purchased Package C, you would save $" << total - costC << endl;
    }
    else if (package == 'B')
    {
        double costC = 69.99;

        if (costC < total)
            cout << "If you purchased Package C, you would save $" << total - costC << endl;
    }

    return 0;
}
