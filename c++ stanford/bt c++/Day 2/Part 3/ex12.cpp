#include <iostream>
#include <vector>
using namespace std;

bool isPow2(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
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
        if (isPow2(a[i]))
        {
            idx = i;
            break;
        }

    if (idx == -1)
        cout << "Khong co so dang 2^k (tra ve 0).\n";
    else
        cout << "So dau tien dang 2^k: " << a[idx]
             << " (vi tri " << idx + 1 << ")\n";
    return 0;
}
