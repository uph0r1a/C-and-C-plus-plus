#include <iostream>
using namespace std;

int main()
{
    float a[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter a: ";
        cin >> a[i];
    }

    for (int i = 0; i < 3 - 1; i++)
    {
        for (int j = 0; j < 3 - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                float temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Ascending order: ";
    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << "\t";
    }

    return 0;
}
