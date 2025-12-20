#include <iostream>
#include <iomanip>
using namespace std;

typedef struct
{
    int HoursWorked;
    float HourlyRate;
} HourlyPaid;

typedef struct
{
    float Salary, Bonus;
} Salaried;

typedef union
{
    HourlyPaid hourlyPaidWorker;
    Salaried salariedWorker;
} Worker;

template <typename T>
void inputValidate(T &number)
{
    while (1)
    {
        cin >> number;
        if (number >= 0)
        {
            break;
        }
        cout << "This data cannot be negative" << endl
             << "Re-enter the data: ";
    }
}

void Payroll(Worker &worker)
{
    int choice;
    cout << "Are you calculating the pay for an 1)hourly paid worker or a 2)salaried worker: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter the hours worked: ";

        while (1)
        {
            inputValidate(worker.hourlyPaidWorker.HoursWorked);
            if (worker.hourlyPaidWorker.HoursWorked <= 80)
            {
                break;
            }
            cout << "Hours worked cannot be greater than 80" << endl
                 << "Re-enter the hours worker worked: ";
        }

        cout << "Enter the pay rate per hour: ";
        inputValidate(worker.hourlyPaidWorker.HourlyRate);

        cout << fixed << setprecision(2) << "Hourly worker pay: $" << worker.hourlyPaidWorker.HoursWorked * worker.hourlyPaidWorker.HourlyRate << endl;
        break;
    case 2:
        cout << "Enter the salary: ";
        inputValidate(worker.salariedWorker.Salary);

        cout << "Enter the bonus: ";
        inputValidate(worker.salariedWorker.Bonus);

        cout << fixed << setprecision(2) << "Salaried worker pay: $" << worker.salariedWorker.Salary + worker.salariedWorker.Bonus << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}

int main(int argc, char const *argv[])
{
    Worker worker;
    Payroll(worker);
    return 0;
}
