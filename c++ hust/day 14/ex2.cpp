#include <iostream>
using namespace std;

class Employee
{
private:
    string employeeName, hireDate;
    int employeeNumber;

public:
    Employee(string name = "", int number = 0, string date = "")
        : employeeName(name),
          employeeNumber(number),
          hireDate(date) {}

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

class ShiftSupervisor : public Employee
{
private:
    int annualSalary, annualBonus;

public:
    ShiftSupervisor(string name = "", int number = 0, string date = "", int salary = 0, int bonus = 0)
        : Employee(name, number, date),
          annualSalary(salary),
          annualBonus(bonus) {}

    void setSalary(int salary)
    {
        annualSalary = salary;
    }

    void setBonus(int bonus)
    {
        annualBonus = bonus;
    }

    int getSalary() const
    {
        return annualSalary;
    }

    int getBonus() const
    {
        return annualBonus;
    }
};

int main(int argc, char const *argv[])
{
    ShiftSupervisor suppervisor("John Doe", 12345, "2023-05-10", 2, 18.75);

    cout << "Employee Name: " << suppervisor.getName() << endl;
    cout << "Employee Number: " << suppervisor.getNumber() << endl;
    cout << "Hire Date: " << suppervisor.getDate() << endl;
    cout << "Salary: $" << suppervisor.getSalary() << endl;
    cout << "Bonus: $" << suppervisor.getBonus() << endl;

    return 0;
}
