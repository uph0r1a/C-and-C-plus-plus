#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int day;
    float earning = 1 * 0.01, sum = 0;
    cout << "Enter the number of days: ";
    while (1)
    {
        cin >> day;
        if (day > 1)
        {
            break;
        }
        cout << "Do not accept a number less than 1 for the number of days worked";
    }

    for (int i = 0; i < day; i++)
    {
        if (i == 0)
        {
            cout << "Day " << i + 1 << ": $" << earning << "\n";
        }
        else
        {
            earning *= 2;
            cout << "Day " << i + 1 << ": $" << earning << "\n";
        }
        sum += earning;
    }

    cout << "Total pay: " << sum;

    return 0;
}
