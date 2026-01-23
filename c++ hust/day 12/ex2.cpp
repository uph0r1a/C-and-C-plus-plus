#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    Employee(string n, int id, string dep, string pos)
    {
        name = n;
        idNumber = id;
        department = dep;
        position = pos;
    }

    Employee(string n, int id)
    {
        name = n;
        idNumber = id;
        department = "";
        position = "";
    }

    Employee()
    {
        name = "";
        idNumber = 0;
        department = "";
        position = "";
    }

    void setName(string n)
    {
        name = n;
    }

    void setId(int id)
    {
        idNumber = id;
    }

    void setDepartment(string dep)
    {
        department = dep;
    }

    void setPosition(string pos)
    {
        position = pos;
    }

    string getName() const
    {
        return name;
    }

    int getId() const
    {
        return idNumber;
    }

    string getDepartment() const
    {
        return department;
    }

    string getPosition() const
    {
        return position;
    }

private:
    string name, department, position;
    int idNumber;
};

int main(int argc, char const *argv[])
{
    Employee employee1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee employee2("Mark Jones", 39119, "IT", "Programmer");
    Employee employee3("Joy Rogers", 81774, "Manufacturing", "Engineer");

    cout << "Employee 1" << endl
         << "Name: " << employee1.getName() << endl
         << "ID Number: " << employee1.getId() << endl
         << "Department: " << employee1.getDepartment() << endl
         << "Position: " << employee1.getPosition() << endl
         << "Employee 2" << endl
         << "Name: " << employee2.getName() << endl
         << "ID Number: " << employee2.getId() << endl
         << "Department: " << employee2.getDepartment() << endl
         << "Position: " << employee2.getPosition() << endl
         << "Employee 3" << endl
         << "Name: " << employee3.getName() << endl
         << "ID Number: " << employee3.getId() << endl
         << "Department: " << employee3.getDepartment() << endl
         << "Position: " << employee3.getPosition() << endl;
    return 0;
}
