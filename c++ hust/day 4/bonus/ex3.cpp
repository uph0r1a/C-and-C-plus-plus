#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, count, temp;
    char reverse[20];
    cout << "Enter a positive interger n: ";
    while (1)
    {
        cin >> n;
        if (n > 0)
        {
            temp = n;
            break;
        }
        cout << "N must be positive\n";
        cout << "Re-enter n: ";
    }

    while (temp > 0)
    {
        temp /= 10;
        count++;
    }

    sprintf(reverse, "%d", n);

    for (int i = count; i >= 0; i--)
    {
        cout << reverse[i];
    }

    return 0;
}
