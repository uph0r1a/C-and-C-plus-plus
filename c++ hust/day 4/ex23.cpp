#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "+";
        }
        cout << "\n";
    }

    cout << "\n\n";

    for (int i = 10; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "+";
        }
        cout << "\n";
    }
    return 0;
}