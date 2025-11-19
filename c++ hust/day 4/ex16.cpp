#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float annual_interest_rate, balance, number_of_months_passed, deposit, total_deposit = 0, withdrawn, total_withdrawn = 0, total_interest = 0;
    cout << "Enter the annual interest rate(%): ";
    while (1)
    {
        cin >> annual_interest_rate;
        if (annual_interest_rate > 0)
        {
            break;
        }
        cout << "Annual interest rate must be a positive number\n";
        cout << "Re-enter the annual interest rate(%): ";
    }

    cout << "Enter the starting balance: ";
    cin >> balance;
    if (balance < 0)
    {
        cout << "The account has been closed\n";
        goto a;
    }

    cout << "Enter the number of months that have passed since the account was established: ";
    while (1)
    {
        cin >> number_of_months_passed;
        if (number_of_months_passed >= 0)
        {
            break;
        }
        cout << "The number of months that have passed cannot be less than 0\n";
        cout << "Re-enter the number of months that have passed since the account was established: ";
    }

    for (int i = 0; i < number_of_months_passed; i++)
    {
        if (balance < 0)
        {
            cout << "The account has been closed\n";
            break;
        }

        cout << "Enter the amount deposited into the account during the month: ";
        while (1)
        {
            cin >> deposit;
            if (deposit >= 0)
            {
                total_deposit += deposit;
                balance += deposit;
                break;
            }
            cout << "The amount deposited cannot be negative\n";
            cout << "Re-enter the amount deposited: ";
        }

        cout << "Enter the amount withdrawn from the account during the month: ";
        while (1)
        {
            cin >> withdrawn;
            if (withdrawn >= 0)
            {
                total_withdrawn += withdrawn;
                balance -= withdrawn;
                break;
            }
            cout << "The amount withdrawn cannot be negative\n";
            cout << "Re-enter the amount withdrawn: ";
        }

        if (balance < 0)
        {
            cout << "The account has been closed\n";
            break;
        }

        balance = balance + balance * ((annual_interest_rate / 100) / 12);
        total_interest += balance * ((annual_interest_rate / 100) / 12);
    }
a:
    cout << "Ending balance: " << balance << "\nTotal amount of deposits: " << total_deposit << "\nTotal amount of withdrawals: " << total_withdrawn << "\nTotal interest earned: " << total_interest;

    return 0;
}