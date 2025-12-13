#include <iostream>
using namespace std;

void Rainfall()
{
    double rainfall[12], sum = 0, max, min;
    int maxMonth = 1, minMonth = 1, month[12];

    for (int i = 0; i < 12; i++)
    {
        cout << "Enter the total rainfall of month " << i + 1 << ": ";
        while (true)
        {
            cin >> rainfall[i];
            if (rainfall[i] >= 0)
            {
                month[i] = i + 1;
                break;
            }
            cout << "Monthly rainfall cannot be negative.\n"
                 << "Re-enter rainfall for month " << i + 1 << ": ";
        }

        if (i == 0)
        {
            max = rainfall[i];
            min = rainfall[i];
        }

        if (rainfall[i] > max)
        {
            max = rainfall[i];
            maxMonth = i + 1;
        }
        if (rainfall[i] < min)
        {
            min = rainfall[i];
            minMonth = i + 1;
        }

        sum += rainfall[i];
    }

    cout << "The total rainfall for the year: " << sum << endl
         << "The average monthly rainfall: " << sum / 12 << endl
         << "The month with the highest amount: " << maxMonth << endl
         << "The month with the lowest amount: " << minMonth << endl;

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12 - i - 1; j++)
        {
            if (rainfall[j] < rainfall[j + 1])
            {
                double temp = rainfall[j];
                rainfall[j] = rainfall[j + 1];
                rainfall[j + 1] = temp;

                int tempMonth = month[j];
                month[j] = month[j + 1];
                month[j + 1] = tempMonth;
            }
        }
    }

    cout << "\nMonths sorted by rainfall (highest to lowest):\n";
    for (int i = 0; i < 12; i++)
    {
        cout << month[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    Rainfall();
    return 0;
}
