#include <iostream>
#include <cmath>
using namespace std;

float presentValue(float future_value, float annual_interest_rate, int number_of_year)
{
    return future_value / pow((1 + (annual_interest_rate / 100)), static_cast<float>(number_of_year));
}

int main(int argc, char const *argv[])
{
    float future_value, annual_interest_rate, present_value;
    int number_of_year;

    cout << "Enter the future value: ";
    cin >> future_value;
    cout << "Enter the annual interest rate: ";
    cin >> annual_interest_rate;
    cout << "Enter the number of year: ";
    cin >> number_of_year;

    present_value = presentValue(future_value, annual_interest_rate, number_of_year);

    cout << "Present value: " << present_value;

    return 0;
}
