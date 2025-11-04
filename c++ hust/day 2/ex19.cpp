#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    float loan_amount, monthly_interest_rate, monthly_payment, annual_interest_rate;
    int number_of_payment;

    cout << "Enter the annual interest rate: ";
    cin >> annual_interest_rate;
    cout << "Enter the number of payments: ";
    cin >> number_of_payment;
    cout << "Enter the amount of the loan: ";
    cin >> loan_amount;

    monthly_interest_rate = annual_interest_rate / 12;
    monthly_payment = (((monthly_interest_rate / 100) * pow((1 + (monthly_interest_rate / 100)), (float)number_of_payment)) / (pow((1 + (monthly_interest_rate / 100)), (float)number_of_payment) - 1)) * loan_amount;

    cout << "Loan Amount:" << setw(20) << "$ " << fixed << setprecision(2) << loan_amount << "\n"
         << "Monthly Interest Rate:" << setw(17) << monthly_interest_rate << "%" << "\n"
         << "Number of Payments:" << setw(21) << number_of_payment << "\n"
         << "Monthly Payment:" << setw(18) << "$   " << monthly_payment << "\n"
         << "Amount Paid Back:" << setw(15) << "$ " << monthly_payment * number_of_payment << "\n"
         << "Interest Paid:" << setw(19) << "$  " << (monthly_payment * number_of_payment) - loan_amount << endl;
    return 0;
}
