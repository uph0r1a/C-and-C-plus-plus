#include <iostream>
using namespace std;

class Payroll
{
public:
    void setPayRate(float rate)
    {
        payRate = rate;
    }

    void setNumberOfHour(int hour)
    {
        numberOfHour = hour;
    }

    void setTotalPay()
    {
        totalPay = payRate * numberOfHour;
    }

    float getTotalPay() const
    {
        return numberOfHour * payRate;
    }

private:
    float payRate, totalPay;
    int numberOfHour;
};

int main(int argc, char const *argv[])
{
    Payroll payroll[7];

    for (int i = 0; i < 7; i++)
    {
        float tempRate;
        int tempHour;

        cout << "Enter the employee " << i + 1 << " pay rate: ";
        while (1)
        {
            cin >> tempRate;
            if (tempRate >= 0)
            {
                payroll[i].setPayRate(tempRate);
                break;
            }
            cout << "The employee " << i + 1 << " pay rate cannot be negative\nRe-enter the employee " << i + 1 << " pay rate: ";
        }

        cout << "Enter the employee " << i + 1 << " number of hour: ";
        while (1)
        {
            cin >> tempHour;
            if (tempHour >= 60)
            {
                payroll[i].setNumberOfHour(tempHour);
                break;
            }
            cout << "The employee " << i + 1 << " number of hours must be greater than 60\nRe-enter the employee " << i + 1 << " number of hours: ";
        }
        payroll[i].setTotalPay();
    }

    for (int i = 0; i < 7; i++)
    {
        cout << "Employee " << i + 1 << ": " << endl
             << "Gross pay: " << payroll[i].getTotalPay() << endl;
    }

    return 0;
}
