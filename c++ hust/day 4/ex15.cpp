#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int employee_number;
    float gross_pay, state_tax, federal_tax, FICA_withholdings;
    float sum_gross_pay = 0, sum_state_tax = 0, sum_federal_tax = 0, sum_FICA_withholdings = 0;

    while (true)
    {
        cout << "Enter employee number: ";
        cin >> employee_number;

        if (employee_number == 0)
            break;

        cout << "Enter gross pay: ";
        cin >> gross_pay;

        while (true)
        {
            cout << "Enter state tax: ";
            while (1)
            {
                cin >> state_tax;
                if (state_tax < gross_pay)
                {
                    break;
                }
                cout << "State tax cannot be greater than gross pay\n";
                cout << "Re-enter state tax: ";
            }

            cout << "Enter federal tax: ";
            while (1)
            {
                cin >> federal_tax;
                if (federal_tax < gross_pay)
                {
                    break;
                }
                cout << "Federal tax cannot be greater than gross pay\n";
                cout << "Re-enter federal tax: ";
            }

            cout << "Enter FICA withholdings: ";
            while (1)
            {
                cin >> FICA_withholdings;
                if (FICA_withholdings < gross_pay)
                {
                    break;
                }
                cout << "FICA withholdings cannot be greater than gross pay\n";
                cout << "Re-enter FICA withholdings: ";
            }

            if (state_tax + federal_tax + FICA_withholdings <= gross_pay)
                break;

            cout << "Sum state tax + federal tax + FICA withholdings cannot exceed gross pay.\n";
            cout << "Re-enter the values.\n";
        }

        sum_gross_pay += gross_pay;
        sum_state_tax += state_tax;
        sum_federal_tax += federal_tax;
        sum_FICA_withholdings += FICA_withholdings;
    }

    cout << "\nTotal gross pay: " << sum_gross_pay
         << "\nTotal state tax: " << sum_state_tax
         << "\nTotal federal tax: " << sum_federal_tax
         << "\nTotal FICA withholdings: " << sum_FICA_withholdings
         << "\nNet pay: " << sum_gross_pay - (sum_state_tax + sum_federal_tax + sum_FICA_withholdings);

    return 0;
}
