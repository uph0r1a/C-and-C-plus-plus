#include <iostream>
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
    return 0;
}
