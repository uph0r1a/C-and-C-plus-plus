#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float balance, fee_pre_check;
    int check;
    cout << "Enter the beginning balance: ";
    cin >> balance;
    if (balance < 0)
    {
        cout << "The account is overdrawn";
    }
    else
    {
        cout << "Enter the number of checks written: ";
        cin >> check;
        if (check < 0)
        {
            cout << "The number of checks written must not be negative";
        }
        else
        {
            if (balance - 10 < 400)
            {
                fee_pre_check = 10 + 15;
            }
            else
            {
                fee_pre_check = 10;
            }

            if (check < 20)
            {
                cout << "The bank's service fees for the month: " << fee_pre_check + check * 0.1;
            }
            else if (check >= 20 && check <= 39)
            {
                cout << "The bank's service fees for the month: " << fee_pre_check + check * 0.08;
            }
            else if (check >= 40 && check <= 59)
            {
                cout << "The bank's service fees for the month: " << fee_pre_check + check * 0.06;
            }
            else
            {
                cout << "The bank's service fees for the month: " << fee_pre_check + check * 0.04;
            }
        }
    }

    return 0;
}
