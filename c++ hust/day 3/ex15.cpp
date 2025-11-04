#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float weight, distance;
    cout << "Enter the weight of the package: ";
    cin >> weight;
    if (weight <= 0 || weight > 20)
    {
        cout << "The company's minimum and maximum weight is 0 and 20kg";
        return 1;
    }

    cout << "Enter the distance it is to be shipped: ";
    cin >> distance;
    if (distance < 10 || distance > 3000)
    {
        cout << "The company's minimum and maximum shipping distances is 10 and 3000kg";
        return 1;
    }

    if (weight <= 2)
    {
        cout << "The charges: " << distance * (1.1 / 500);
    }
    else if (weight > 2 && weight <= 6)
    {
        cout << "The charges: " << distance * (2.2 / 500);
    }
    else if (weight > 6 && weight <= 10)
    {
        cout << "The charges: " << distance * (3.7 / 500);
    }
    else
    {
        cout << "The charges: " << distance * (4.8 / 500);
    }

    return 0;
}
