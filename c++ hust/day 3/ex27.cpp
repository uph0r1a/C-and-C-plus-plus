#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    char package;
    float minutes, total;
    string month;

    while (true)
    {
        cout << "Enter the package purchased (A, B, or C): ";
        cin >> package;
        package = toupper(package);

        if (package == 'A' || package == 'B' || package == 'C')
            break;
        cout << "Invalid input. Please enter A, B, or C.\n";
    }

    while (true)
    {
        cout << "Enter the month: ";
        getline(cin, month);
        getline(cin, month);
        cout << "Enter the number of minutes used: ";
        cin >> minutes;

        if (month == "January" || month == "january")
        {
            if (minutes / 60 > 744)
            {
                break;
            }
            cout << "The number of minutes entered must not be more than the maximum for the entire month";
        }
        else if (month == "February" || month == "february")
        {
            if (minutes / 60 > 672)
            {
                break;
            }
            cout << "The number of minutes entered must not be more than the maximum for the entire month";
        }
        else if (month == "March" || month == "march")
        {
            if (minutes / 60 > 744)
            {
                break;
            }
            cout << "The number of minutes entered must not be more than the maximum for the entire month";
        }
        else if (month == "April" || month == "april")
        {
            if (minutes / 60 > 720)
            {
                break;
            }
            cout << "The number of minutes entered must not be more than the maximum for the entire month";
        }
        else if (month == "May" || month == "may")
        {
            if (minutes / 60 > 744)
            {
                break;
            }
            cout << "The number of minutes entered must not be more than the maximum for the entire month";
        }
        else if (month == "June" || month == "june")
        {
            if (minutes / 60 > 720)
            {
                break;
            }
            cout << "The number of minutes entered must not be more than the maximum for the entire month";
        }
        else if (month == "July" || month == "july")
        {
            if (minutes / 60 > 744)
            {
                break;
            }
            cout << "The number of minutes entered must not be more than the maximum for the entire month";
        }
        else if (month == "August" || month == "august")
        {
            if (minutes / 60 > 744)
            {
                break;
            }
            cout << "The number of minutes entered must not be more than the maximum for the entire month";
        }
        else if (month == "September" || month == "september")
        {
            if (minutes / 60 > 720)
            {
                break;
            }
            cout << "The number of minutes entered must not be more than the maximum for the entire month";
        }
        else if (month == "October" || month == "october")
        {
            if (minutes / 60 > 744)
            {
                break;
            }
            cout << "The number of minutes entered must not be more than the maximum for the entire month";
        }
        else if (month == "November" || month == "november")
        {
            if (minutes / 60 > 720)
            {
                break;
            }
            cout << "The number of minutes entered must not be more than the maximum for the entire month";
        }
        else if (month == "December" || month == "december")
        {
            if (minutes / 60 > 744)
            {
                break;
            }
            cout << "The number of minutes entered must not be more than the maximum for the entire month";
        }
        else
        {
            break;
        }
        cout << "Invalid month";
    }

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
