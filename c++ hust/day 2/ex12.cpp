#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float celsius, fahrenheit;
    cout << "Enter Celsius temperatures: ";
    cin >> celsius;
    fahrenheit = 1.8 * celsius + 32;
    cout << fahrenheit << endl;
    return 0;
}
