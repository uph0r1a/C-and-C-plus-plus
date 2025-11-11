#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int number, sum = 0;
    cout << "Enter a positive integer value: ";
    while (1)
    {
        cin >> number;
        if (number >= 1)
        {
            break;
            ;
        }
        cout << "Do not accept a negative starting number\n";
        cout << "Re-enter a positive integer value: ";
    }

    for (int i = 1; i <= number; i++)
    {
        sum += i;
    }

    cout << "Sum of all the integers from 1 up to " << number << ": " << sum;

    return 0;
}
