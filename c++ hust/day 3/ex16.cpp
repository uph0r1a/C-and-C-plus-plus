#include <iostream>
#include <string>
using namespace std;

struct Runner
{
    string name;
    float time;
};

int main(int argc, char const *argv[])
{
    Runner runner[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the name of runner " << i + 1 << ": ";
        cin >> runner[i].name;

    loop:
        cout << "Enter the time of runner " << i + 1 << ": ";
        cin >> runner[i].time;

        if (runner[i].time < 0)
        {
            cout << "Only accept positive numbers for the times\n";
            goto loop;
        }
    }

    for (int i = 0; i < 3 - 1; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            if (runner[j].time > runner[j + 1].time)
            {
                Runner temp = runner[j];
                runner[j] = runner[j + 1];
                runner[j + 1] = temp;
            }
        }
    }

    cout << "\nFirst place: " << runner[0].name
         << "\nSecond place: " << runner[1].name
         << "\nThird place: " << runner[2].name << endl;

    return 0;
}
