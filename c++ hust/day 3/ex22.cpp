#include <iostream>
#include <string>
using namespace std;

struct Substances
{
    string name;
    float freeze, boil;
};

int main(int argc, char const *argv[])
{
    Substances substances[] = {
        {"Ethyl alcohol", -173, 172},
        {"Mercury", -38, 676},
        {"Oxygen", -362, -306},
        {"Water", 32, 212}};
    float condition;

    cout << "Enter a temperature";
    cin >> condition;

    cout << "Freeze: \n";
    for (int i = 0; i < 4; i++)
    {
        if (condition >= substances[i].freeze)
        {
            cout << substances[i].name << "\n";
        }
    }

    cout << "Boil: \n";
    for (int i = 0; i < 4; i++)
    {
        if (condition <= substances[i].boil)
        {
            cout << substances[i].name << "\n";
        }
    }
    return 0;
}
