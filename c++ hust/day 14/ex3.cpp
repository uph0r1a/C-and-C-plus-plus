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

class ProductionWorker : public Employee
{
private:
    int shift;
    double hourlyPayRate;

public:
    ProductionWorker(string name, int number, string date, int s, double rate)
        : Employee(name, number, date),
          shift((s == 1 || s == 2 ? s : 1)),
          hourlyPayRate(rate) {}

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

class TeamLeader : public ProductionWorker
{
private:
    int monthlyBonus, requiredTrainningHour, attendedTrainingHour;

public:
    TeamLeader(string name, int number, string date, int s, double rate, int bonus, int required, int attended)
        : ProductionWorker(name, number, date, s, rate),
          monthlyBonus(bonus),
          requiredTrainningHour(required),
          attendedTrainingHour(attended) {}

    void setMonthlyBonus(int bonus)
    {
        monthlyBonus = bonus;
    }

    void setRequiredTrainningHour(int required)
    {
        requiredTrainningHour = required;
    }

    void setAttendedTrainingHour(int attended)
    {
        attendedTrainingHour = attended;
    }

    int getMonthlyBonus() const
    {
        return monthlyBonus;
    }

    int getRequiredTrainningHour() const
    {
        return requiredTrainningHour;
    }

    int getAttendedTrainingHour() const
    {
        return attendedTrainingHour;
    }
};

int main(int argc, char const *argv[])
{
    TeamLeader leader("John Doe", 12345, "2023-05-10", 2, 18.75, 10, 20, 30);

    cout << "Employee Name: " << leader.getName() << endl;
    cout << "Employee Number: " << leader.getNumber() << endl;
    cout << "Hire Date: " << leader.getDate() << endl;
    cout << "Shift: ";
    if (leader.getShift() == 1)
        cout << "Day Shift" << endl;
    else
        cout << "Night Shift" << endl;

    cout << "Hourly Pay Rate: $" << leader.getHourlyPayRate() << endl;
    cout << "Monthly Bonus: $" << leader.getMonthlyBonus() << endl;
    cout << "Required Trainning Hour: " << leader.getRequiredTrainningHour() << endl;
    cout << "Attended Training Hour: " << leader.getAttendedTrainingHour() << endl;

    return 0;
}
