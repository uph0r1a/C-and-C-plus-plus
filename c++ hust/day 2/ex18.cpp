#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    float principal, interest_rate, amount;
    int time_compounded;
    cout << "Enter the principal: ";
    cin >> principal;
    cout << "Enter the interest rate: ";
    cin >> interest_rate;
    cout << "Enter the number of times the interest is compounded: ";
    cin >> time_compounded;

    amount = principal * pow((1 + (interest_rate / 100) / (float)time_compounded), time_compounded);

    cout << "Interest Rate:" << setw(20) << fixed << setprecision(2) << interest_rate << "%" << "\n"
         << "Times Compounded:" << setw(17) << time_compounded << "\n"
         << "Principal:" << setw(17) << "$ " << fixed << setprecision(2) << principal << "\n"
         << "Interest:" << setw(20) << "$   " << fixed << setprecision(2) << amount - principal << "\n"
         << "Amount in Savings:" << setw(9) << "$ " << fixed << setprecision(2) << amount << endl;
    return 0;
}
