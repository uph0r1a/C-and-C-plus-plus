#include <iostream>
#include <vector>
#include <string>
using namespace std;

class PhoneBookEntry
{
private:
    string personName, phoneNumber;

public:
    PhoneBookEntry(string name, string number)
        : personName(name),
          phoneNumber(number) {}

    void display()
    {
        cout << "Name: " << personName << endl
             << "Phone number: " << phoneNumber << endl
             << endl;
    }
};

int main(int argc, char const *argv[])
{
    vector<PhoneBookEntry> phoneBook{
        {"A", "0928032"},
        {"B", "0928032"},
        {"D", "0928032"},
        {"E", "0928032"},
    };

    for (int i = 0; i < phoneBook.size(); i++)
    {
        phoneBook[i].display();
    }

    return 0;
}
