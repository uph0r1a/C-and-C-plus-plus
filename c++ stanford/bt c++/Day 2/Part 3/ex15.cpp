#include <iostream>
#include <vector>
#include <algorithm>
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
        cout << "Nhap n (>= 1): ";
        cin >> n;
    } while (n < 1);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "  a[" << i + 1 << "]: ";
        cin >> a[i];
    }

    int mx = *max_element(a.begin(), a.end());
    int candidate = max(mx + 1, 2);
    while (!isPrime(candidate))
        candidate++;

    cout << "Max mang = " << mx << "\n";
    cout << "So nguyen to nho nhat lon hon max: " << candidate << "\n";
    return 0;
}
