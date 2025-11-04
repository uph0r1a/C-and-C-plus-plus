#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
    char package;
    float minutes;

loop1:
    cout << "Enter the package the customer has purchased";
    cin >> package;

    if (toupper(package) != 'A' || toupper(package) != 'B' || toupper(package) != 'C')
    {
        cout << "Only selects package A, B, or C\n";
        goto loop1;
    }

    cout << "Enter the minutes used: ";
    cin >> minutes;

    if (toupper(package) == 'A')
    {
        if (minutes > 450)
        {
            cout << "The total amount due: " << 39.99 + (450 - minutes) * 0.45;
        }
        cout << "The total amount due: " << 39.99;
    }
    else if (toupper(package) == 'A')
    {
        if (minutes > 900)
        {
            cout << "The total amount due: " << 59.99 + (900 - minutes) * 0.4;
        }
        cout << "The total amount due: " << 59.99;
    }
    else
    {
        cout << "The total amount due: " << 69.99;
    }

    return 0;
}
