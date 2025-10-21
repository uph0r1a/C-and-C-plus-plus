#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char month[3][10];
    float amount_each_month[3], sum = 0;

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the name of month " << i + 1 << ": ";
        cin >> month[i];
        cout << "Enter the amount of rain (in inches) that fell in " << month[i] << ": ";
        cin >> amount_each_month[i];
        sum += amount_each_month[i];
    }
    cout << "The average rainfall for " << month[0] << ", " << month[1] << ", " << month[2] << " is " << sum / 3 << " inches.";
    return 0;
}
