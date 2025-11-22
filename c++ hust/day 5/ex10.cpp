#include <iostream>
#include <cmath>
using namespace std;

float futureValue(float present_value, float monthly_interest_rate, int number_of_months)
{
    return present_value * pow((1 + (monthly_interest_rate / 100)), static_cast<float>(number_of_months));
}

int main(int argc, char const *argv[])
{
    float future_value, monthly_interest_rate, present_value;
    int number_of_months;

    cout << "Enter the present value: ";
    cin >> present_value;
    cout << "Enter the monthly interest rate: ";
    cin >> monthly_interest_rate;
    cout << "Enter the number of months: ";
    cin >> number_of_months;

    future_value = futureValue(present_value, monthly_interest_rate, number_of_months);

    cout << "Future  value: " << future_value;

    return 0;
}
