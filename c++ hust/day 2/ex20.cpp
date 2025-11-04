#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    const float pi = 3.14159;
    float r;

    cout << "Enter the diameter of the pizza in inches: ";
    cin >> r;

    cout << "Number of slices: " << fixed << setprecision(1) << (pi * pow(r, 2)) / 14.125 << endl;
    return 0;
}
