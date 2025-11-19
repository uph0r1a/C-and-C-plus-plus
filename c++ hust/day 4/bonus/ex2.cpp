#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, flag = 1;
    cout << "Enter a positive interger n: ";
    while (1)
    {
        cin >> n;
        if (n > 0)
        {
            break;
        }
        cout << "N must be positive\n";
        cout << "Re-enter n: ";
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "N is prime";
    }
    else
    {
        cout << "N is not prime";
    }

    return 0;
}
