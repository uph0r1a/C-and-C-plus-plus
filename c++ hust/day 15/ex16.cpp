#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string employeeName, hireDate;
    int employeeNumber;

public:
    Employee(string name = "", int number = 0, string date = "")
        : employeeName(name),
          hireDate(date)
    {
        if (number < 0 || number > 9999)
        {
            throw InvalidEmployeeNumber();
        }
        employeeNumber = number;
    }

    class InvalidEmployeeNumber
    {
    };

    void setName(string name)
    {
        employeeName = name;
    }

    void setNumber(int number)
    {
        employeeNumber = number;
    }

    void setDate(string date)
    {
        hireDate = date;
    }

    string getName() const
    {
        return employeeName;
    }

    int getNumber() const
    {
        return employeeNumber;
    }

    string getDate() const
    {
        return hireDate;
    }
};

class ProductionWorker : public Employee
{
private:
    int shift;
    double hourlyPayRate;

public:
    ProductionWorker(string name, int number, string date, int s, double rate)
        : Employee(name, number, date)
    {
        if (s < 1 || s > 2)
        {
            throw InvalidShift();
        }

        if (rate < 0)
        {
            throw InvalidPayRate();
        }

        shift = s;
        hourlyPayRate = rate;
    }

    class InvalidShift
    {
    };

    class InvalidPayRate
    {
    };

    void setShift(int s)
    {
        if (s == 1 || s == 2)
        {
            shift = s;
        }
    }

    void setHourlyPayRate(double rate)
    {
        hourlyPayRate = rate;
    }

    int getShift() const
    {
        return shift;
    }

    double getHourlyPayRate() const
    {
        return hourlyPayRate;
    }
};

int main(int argc, char const *argv[])
{
    ProductionWorker worker("John Doe", 1234, "2023-05-10", 1, 18.75);

    cout << "Employee Name: " << worker.getName() << endl;
    cout << "Employee Number: " << worker.getNumber() << endl;
    cout << "Hire Date: " << worker.getDate() << endl;

    cout << "Shift: ";
    if (worker.getShift() == 1)
        cout << "Day Shift" << endl;
    else
        cout << "Night Shift" << endl;

    cout << "Hourly Pay Rate: $" << worker.getHourlyPayRate() << endl;

    return 0;
}
