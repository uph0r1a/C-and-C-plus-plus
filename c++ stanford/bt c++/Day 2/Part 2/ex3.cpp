#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i <= (int)sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap n (1 <= n < 20): ";
        cin >> n;
    } while (n < 1 || n >= 20);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "  a[" << (i + 1) << "]: ";
        cin >> a[i];
    }

    long long tong = 0;
    cout << "So nguyen to: ";
    bool co = false;
    for (int x : a)
        if (isPrime(x))
        {
            cout << x << " ";
            tong += x;
            co = true;
        }
    if (!co)
        cout << "(khong co)";
    cout << "\nTong = " << tong << "\n";
    return 0;
}
