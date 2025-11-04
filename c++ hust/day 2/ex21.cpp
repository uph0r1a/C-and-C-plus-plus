#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    const float pi = 3.14159;
    float r;
    int number_of_people;

    cout << "Enter the number of people: ";
    cin >> number_of_people;
    cout << "Enter the diameter of the pizza in inches: ";
    cin >> r;

    cout << "Number of pizzas: " << fixed << setprecision(1) << ((pi * pow(r, 2)) / 14.125) / number_of_people * 4 << endl;
    return 0;
}
