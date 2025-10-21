#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float gallon_of_gas_can_hold = 0, mile_driven_full_tank = 0, mile_per_gallon;
    cout << "Enter the number of gallon of gas the car can hold: ";
    cin >> gallon_of_gas_can_hold;
    cout << "Enter the number of miles it can be driven on a full tank: ";
    cin >> mile_driven_full_tank;
    mile_per_gallon = mile_driven_full_tank / gallon_of_gas_can_hold;
    cout << mile_per_gallon << endl;
    return 0;
}
