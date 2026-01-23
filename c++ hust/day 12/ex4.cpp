#include <iostream>
#include <string>
using namespace std;

class PersonalInformation
{
public:
    void setName(string n)
    {
        name = n;
    }

    void setAddress(string adr)
    {
        address = adr;
    }

    void setAge(int ag)
    {
        age = ag;
    }

    void setPhoneNumber(string tel)
    {
        phoneNumber = tel;
    }

    string getName() const
    {
        return name;
    }

    string getAddress() const
    {
        return address;
    }

    int getAge() const
    {
        return age;
    }

    string getPhoneNumber() const
    {
        return phoneNumber;
    }

private:
    string name, address, phoneNumber;
    int age;
};

int main(int argc, char const *argv[])
{
    PersonalInformation personalInfo;

    personalInfo.setName("Thai Duc Tri");
    personalInfo.setAddress("Ha Noi");
    personalInfo.setAge(19);
    personalInfo.setPhoneNumber("0*********");

    cout << "Name: " << personalInfo.getName() << endl
         << "Address: " << personalInfo.getAddress() << endl
         << "Age: " << personalInfo.getAge() << endl
         << "Phone Number: " << personalInfo.getPhoneNumber() << endl;

    return 0;
}
