#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float actual_value, tax_rate, actual_assessed_value, assessed_value_post_redemption, property_tax, quarterly_payment;
    cout << "Enter the actual value of a piece of property: ";
    cin >> actual_value;
    cout << "Enter the current tax rate for each $100 of assessed value: ";
    cin >> tax_rate;

    cout << "Annual property tax: " << ((actual_assessed_value * 0.6) - 5000) * (tax_rate / 100) << "\n"
         << "Quarterly tax bill: " << (((actual_assessed_value * 0.6) - 5000) * (tax_rate / 100)) / 4 << endl;
    return 0;
}
