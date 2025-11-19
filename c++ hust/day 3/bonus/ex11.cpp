#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float a[4], max = 0;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter a: ";
        cin >> a[i];
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    cout << "Max: " << max;
    return 0;
}
