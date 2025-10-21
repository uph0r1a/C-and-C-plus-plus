#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float loan_payment, insurance, gas, oil, tires, maintenance, total_monthly;
    cout << "Enter loan payment: ";
    cin >> loan_payment;
    cout << "Enter insurance: ";
    cin >> insurance;
    cout << "Enter gas: ";
    cin >> gas;
    cout << "Enter oil: ";
    cin >> oil;
    cout << "Enter tires: ";
    cin >> tires;
    cout << "Enter maintenance: ";
    cin >> maintenance;
    total_monthly = loan_payment + insurance + gas + oil + tires + maintenance;
    cout << "Total monthly cost: " << total_monthly << "\n"
         << "Total annual cost: " << total_monthly * 12 << endl;
    return 0;
}
