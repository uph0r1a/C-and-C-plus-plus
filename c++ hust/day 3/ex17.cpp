#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Vaults
{
    float height;
    int date;
};

int main(int argc, char const *argv[])
{
    string name;
    Vaults vaults[3];

    cout << "Enter the name of a pole vaulter: ";
    getline(cin, name);

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the date number " << i + 1 << ": ";
        cin >> vaults[i].date;
    loop:
        cout << "Enter the vault heights number " << i + 1 << ": ";
        cin >> vaults[i].height;
        if (vaults[i].height < 2 || vaults[i].height > 5)
        {
            cout << "Only accept values between 2.0 and 5.0 for the heights.\n";
            goto loop;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            if (vaults[j].height < vaults[j + 1].height)
            {
                Vaults temp = vaults[j];
                vaults[j] = vaults[j + 1];
                vaults[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ") Date: " << vaults[i].date << "\n"
             << "Height: " << vaults[i].height << "\n";
    }
    return 0;
}
