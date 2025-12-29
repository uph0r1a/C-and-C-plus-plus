#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    double base, power;
    cout << "Enter the base of wavelength: ";
    cin >> base;
    cout << "Enter the power of wavelength (e.g. -6 for 10^-6): ";
    cin >> power;

    double wavelength = base * pow(10, power);

    if (wavelength > 1e-1)
    {
        cout << "Radio Waves";
    }
    else if (wavelength > 1e-3)
    {
        cout << "Microwaves";
    }
    else if (wavelength > 7e-7)
    {
        cout << "Infrared";
    }
    else if (wavelength > 4e-7)
    {
        cout << "Visible Light";
    }
    else if (wavelength > 1e-8)
    {
        cout << "Ultraviolet";
    }
    else if (wavelength > 1e-11)
    {
        cout << "X Rays";
    }
    else
    {
        cout << "Gamma Rays";
    }

    return 0;
}
