#include <iostream>
#include <cmath>
using namespace std;

class MortgagePayment
{
public:
    void setPayment(float p)
    {
        payment = p;
    }

    void setLoan(float l)
    {
        loan = l;
    }

    void setRate(float r)
    {
        rate = r;
    }

    void setYear(int y)
    {
        year = y;
    }

    float getTerm() const
    {
        return pow((1 + rate / 12), 12 * year);
    }

    float getPayment() const
    {
        return (loan * (rate / 12) * getTerm()) / (getTerm() - 1);
    }

    float getEndOfLoan() const
    {
        return getPayment() * 12;
    }

private:
    float payment, loan, rate;
    int year;
};

int main(int argc, char const *argv[])
{
    MortgagePayment mortgage;
    float tempPayment, tempLoan, tempRate;
    int tempYear;

    cout << "Enter the monthly payment: ";
    while (1)
    {
        cin >> tempPayment;
        if (tempPayment >= 0)
        {
            mortgage.setPayment(tempPayment);
            break;
        }
        cout << "The monthly payment cannot be negative\nRe-enter the monthly payment: ";
    }

    cout << "Enter the dollar amount of the loan: ";
    while (1)
    {
        cin >> tempLoan;
        if (tempLoan >= 0)
        {
            mortgage.setLoan(tempLoan);
            break;
        }
        cout << "The dollar amount of the loan cannot be negative\nRe-enter the dollar amount of the loan: ";
    }

    cout << "Enter the annual interest rate: ";
    while (1)
    {
        cin >> tempRate;
        if (tempRate >= 0)
        {
            mortgage.setRate(tempRate);
            break;
        }
        cout << "The annual interest rate cannot be negative\nRe-enter the annual interest rate: ";
    }

    cout << "Enter the number of years of the loan: ";
    while (1)
    {
        cin >> tempYear;
        if (tempYear >= 0)
        {
            mortgage.setYear(tempYear);
            break;
        }
        cout << "The number of years of the loan cannot be negative\nRe-enter the number of years of the loan: ";
    }

    cout << "The monthly payment amount: " << mortgage.getPayment() << endl
         << "The total amount paid to the bank at the end of the loan period: " << mortgage.getEndOfLoan() << endl;

    return 0;
}
