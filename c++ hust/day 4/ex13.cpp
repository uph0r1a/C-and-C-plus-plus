#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int number, max, min;
    max = -2147483648;
    min = 2147483647;
    cout << "Enter a series of integers: ";
    while (1)
    {
        cin >> number;

        if (number == -99)
        {
            break;
        }
        if (number > max)
        {
            max = number;
        }
        if (number < min)
        {
            min = number;
        }
    }

    cout << "Max: " << max << "\n"
         << "Min: " << min;

    return 0;
}
