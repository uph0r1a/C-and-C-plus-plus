#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int interger, hundred = 0, i = 0;
    int number[4];

    cout << "Enter the interger: ";
    cin >> interger;

    while (hundred == 0)
    {
        number[i] = interger - (interger / 10) * 10;
        interger /= 10;
        if (i == 2)
        {
            hundred = number[i];
            break;
        }
        i++;
    }

    cout << hundred;

    return 0;
}
