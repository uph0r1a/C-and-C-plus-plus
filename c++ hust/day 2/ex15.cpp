#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float actual_value, assesment_value, property_tax;
    cout << "Enter the actual value of a piece of property: ";
    cin >> actual_value;
    assesment_value = actual_value * 0.6;
    property_tax = assesment_value * 0.0075;
    cout << "Assessment value: " << assesment_value << "\n"
         << "Property tax: " << property_tax << endl;
    return 0;
}
