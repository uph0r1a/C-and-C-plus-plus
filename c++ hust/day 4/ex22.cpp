#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int count;
    cout << "Enter a positive interger smaller than 15: ";
    while (1)
    {
        cin >> count;
        if (count <= 15 && count > 0)
        {
            break;
        }
        cout << "The positive interger must be smaller than 15\n";
        cout << "Re-enter a positive interger smaller than 15: ";
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            cout << "X";
        }
        cout << "\n";
    }

    return 0;
}
