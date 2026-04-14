#include <iostream>
using namespace std;

template <typename T>
class BankAccount
{
protected:
    T balance, annualInterestRate, monthlyServiceCharges;
    int numberDepositsThisMonth, numberWithdrawals;

public:
    BankAccount(T b, T rate)
        : balance(b),
          annualInterestRate(rate)
    {
        numberDepositsThisMonth = 0;
        numberWithdrawals = 0;
        monthlyServiceCharges = 0;
    }

    virtual void deposit(T deposit)
    {
        balance += deposit;
        numberDepositsThisMonth++;
    }

    virtual void withdraw(T withdraw)
    {
        balance -= withdraw;
        numberWithdrawals++;
    }

    virtual void calcInt()
    {
        T monthlyInterestRate = annualInterestRate / 12;
        T monthlyInterest = balance * monthlyInterestRate;
        balance += monthlyInterest;
    }

    virtual void monthlyProc()
    {
        balance -= monthlyServiceCharges;
        calcInt();
        numberWithdrawals = 0;
        numberDepositsThisMonth = 0;
        monthlyServiceCharges = 0;
    }

    T getBalance() const { return balance; }
};

class SavingAccount : public BankAccount<double>
{
private:
    bool status;

public:
    SavingAccount(double b, double rate)
        : BankAccount<double>(b, rate)
    {
        status = (b >= 25);
    }

    void withdraw(double withdraw) override
    {
        if (!status)
        {
            cout << "Your account is inactive\nWithdrawal denied." << endl;
            return;
        }
        BankAccount<double>::withdraw(withdraw);
    }

    void deposit(double deposit) override
    {
        BankAccount<double>::deposit(deposit);
        if (!status && balance >= 25)
        {
            status = true;
            cout << "Your account is reactivate" << endl;
        }
    }

    void monthlyProc() override
    {
        if (numberWithdrawals >= 4)
        {
            monthlyServiceCharges += (numberWithdrawals - 4);
        }
        BankAccount<double>::monthlyProc();
        status = (balance >= 25);
    }
};

class CheckingAccount : public BankAccount<double>
{
public:
    CheckingAccount(double b, double rate)
        : BankAccount<double>(b, rate) {}

    void withdraw(double withdraw) override
    {
        if (balance - withdraw < 0)
        {
            monthlyServiceCharges += 15;
            cout << "Insufficient funds. $15 fee applied." << endl;
        }
        else
        {
            BankAccount<double>::withdraw(withdraw);
        }
    }

    void monthlyProc() override
    {
        monthlyServiceCharges += 5 + (0.1 * numberWithdrawals);
        BankAccount<double>::monthlyProc();
    }
};

int main(int argc, char const *argv[])
{
    cout << "===== SAVINGS ACCOUNT =====\n";

    SavingAccount s(50, 0.12);

    s.deposit(20);
    s.withdraw(10);
    s.withdraw(10);
    s.withdraw(10);
    s.withdraw(10);
    s.withdraw(10);

    s.monthlyProc();

    cout << "Final Savings Balance: " << s.getBalance() << endl;

    cout << "\n===== CHECKING ACCOUNT =====\n";

    CheckingAccount c(100, 0.10);

    c.deposit(50);
    c.withdraw(120);
    c.withdraw(20);

    c.monthlyProc();

    cout << "Final Checking Balance: " << c.getBalance() << endl;

    return 0;
}
