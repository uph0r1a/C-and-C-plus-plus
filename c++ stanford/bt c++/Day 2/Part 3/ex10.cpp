#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isGanh(int num)
{
    num = abs(num);
    if (num == 0)
        return false;
    int sumLe = 0, sumChan = 0, pos = 1;
    while (num > 0)
    {
        int d = num % 10;
        if (pos % 2 == 1)
            sumLe += d;
        else
            sumChan += d;
        num /= 10;
        pos++;
    }
    return sumLe == sumChan;
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
        if (isGanh(a[i]))
        {
            idx = i;
            break;
        }

    if (idx == -1)
        cout << "Khong co so ganh.\n";
    else
        cout << "So ganh dau tien: " << a[idx]
             << " (vi tri " << idx + 1 << ")\n";
    return 0;
}
