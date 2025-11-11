#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int year;
    float rainfall, average = 0, sum = 0;

    cout << "Enter the number of years: ";
    while (1)
    {
        cin >> year;
        if (year >= 1)
        {
            break;
        }
        cout << "Do not accept a number less than 1 for the number of years\n";
        cout << "Re-enter the number of years: ";
    }

    for (int i = 0; i < year; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            cout << "Enter the inches of rainfall for month " << j << ": ";
            while (1)
            {
                cin >> rainfall;
                if (rainfall >= 0)
                {
                    break;
                }
                cout << "Do not accept negative numbers for the monthly rainfall\n";
                cout << "Re-enter the inches of rainfall for month " << j << ": ";
            }

            sum += rainfall;
        }
    }

    average = sum / (static_cast<float>(year * 12));

    cout << "The number of months: " << year * 12 << "\n"
         << "The total inches of rainfall: " << sum << "\n"
         << "The average rainfall per month for the entire period: " << average;

    return 0;
}
