#include <iostream>
using namespace std;

float Celsius(float fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32);
}

int main(int argc, char const *argv[])
{
    float celsius;

    cout << "Celsius\t\tFahrenheit\n";
    for (int i = 1; i <= 20; i++)
    {
        celsius = Celsius(static_cast<float>(i));
        cout << celsius << "\t\t" << i << endl;
    }

    return 0;
}
