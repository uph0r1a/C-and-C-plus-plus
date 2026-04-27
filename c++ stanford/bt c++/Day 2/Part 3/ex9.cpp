#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPerfectSquare(int n)
{
    if (n < 0)
        return false;
    long long s = llround(sqrt((double)n));
    return s * s == n;
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
        if (isPerfectSquare(a[i]))
        {
            idx = i;
            break;
        }

    if (idx == -1)
        cout << "Khong co so chinh phuong.\n";
    else
        cout << "So chinh phuong dau tien: " << a[idx]
             << " (vi tri " << idx + 1 << ")\n";
    return 0;
}
