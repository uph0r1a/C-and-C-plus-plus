#include <iostream>
using namespace std;

void Rainfall()
{
    double rainfall[12], sum = 0, max, min;
    int maxMonth, minMonth;
    for (int i = 0; i < 12; i++)
    {
        cout << "Enter the total rainfall of month " << i + 1 << ": ";
        while (1)
        {
            cin >> rainfall[i];
            if (rainfall[i] >= 0)
            {
                break;
            }
            cout << "Monthly rainfall figures cannot be negative\nRe-enter the total rainfall of month " << i + 1 << ": ";
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
         << "The months with the highest amount: " << maxMonth << endl
         << "The months with the lowest amount: " << minMonth;
}

int main(int argc, char const *argv[])
{
    Rainfall();
    return 0;
}
