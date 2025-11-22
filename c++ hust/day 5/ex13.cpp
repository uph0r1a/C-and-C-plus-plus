#include <iostream>
using namespace std;

int Number_of_emplyees()
{
    int number_of_employees;
    cout << "Enter the number of employees: ";
    while (1)
    {
        cin >> number_of_employees;
        if (number_of_employees >= 1)
        {
            break;
        }
        cout << "Number of employees cannot be less than 1\nRe-enter the number of employees: ";
    }

    return number_of_employees;
}

int Day_absent(int number_of_employees)
{
    int day_absent, sum = 0;
    for (int i = 0; i < number_of_employees; i++)
    {
        cout << "Enter the number of days employee " << i + 1 << " missed during the past year: ";
        while (1)
        {
            cin >> day_absent;
            if (day_absent >= 0)
            {
                sum += day_absent;
                break;
            }
        }
    }
    return sum;
}

double Average_day_absent(int number_of_employee, int total_day_absent)
{
    return total_day_absent / number_of_employee;
}

int main(int argc, char const *argv[])
{
    int number_of_employees = Number_of_emplyees();
    int total_day_absent = Day_absent(number_of_employees);
    double average_day_absent = Average_day_absent(number_of_employees, total_day_absent);

    cout << "Average day absent: " << average_day_absent;
    return 0;
}
