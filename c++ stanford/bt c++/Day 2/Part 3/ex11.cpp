#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int chuSoDau(int n)
{
    n = abs(n);
    while (n >= 10)
        n /= 10;
    return n;
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

    int idx = -1;
    for (int i = 0; i < n; i++)
        if (chuSoDau(a[i]) % 2 != 0)
        {
            idx = i;
            break;
        }

    if (idx == -1)
        cout << "Khong co so nao co chu so dau la le.\n";
    else
        cout << "So dau tien co chu so dau la le: " << a[idx]
             << " (chu so dau: " << chuSoDau(a[idx]) << ", vi tri " << idx + 1 << ")\n";
    return 0;
}
