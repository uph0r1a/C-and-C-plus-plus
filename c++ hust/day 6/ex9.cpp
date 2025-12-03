#include <iostream>
using namespace std;

void Payroll()
{
    int empId[7] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    int hours[7];
    double payRate[7];
    double wages[7];

    for (int i = 0; i < 7; i++)
    {
        cout << "Employee number " << empId[i] << ": " << endl;
        cout << "Enter the employee's hours: ";
        while (1)
        {
            cin >> hours[i];
            if (hours[i] >= 0)
            {
                break;
            }
            cout << "Hours cannot be negative\nRe-enter the employee's hours: ";
        }

        cout << "Enter the employee's pay rate: ";
        while (1)
        {
            cin >> payRate[i];
            if (payRate[i] >= 15)
            {
                break;
            }
            cout << "Pay rate cannot be less than 15\nRe-enter the employee's pay rate: ";
        }

        wages[i] = hours[i] * payRate[i];
    }

    for (int i = 0; i < 7; i++)
    {
        cout << "Employee number: " << empId[i] << endl
             << "Gross wages: " << wages[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    Payroll();
    return 0;
}
