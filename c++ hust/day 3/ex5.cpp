#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
    float weight, height, bmi;
    cout << "Enter weight: ";
    cin >> weight;
    cout << "Enter height: ";
    cin >> height;

    bmi = (weight * 703) / pow(height, 2);

    if (bmi > 25)
    {
        cout << "The person is overweight";
    }
    else if (bmi < 18.5)
    {
        cout << "The person is underweight";
    }
    else
    {
        cout << "The person's weight is optimal";
    }

    return 0;
}
