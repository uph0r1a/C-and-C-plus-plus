#include <iostream>
#include <vector>
using namespace std;

bool isPow5(int n)
{
    if (n <= 0)
        return false;
    while (n % 5 == 0)
        n /= 5;
    return n == 1;
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

    int best = 0;
    bool found = false;
    for (int v : a)
        if (isPow5(v) && (!found || v > best))
        {
            best = v;
            found = true;
        }

    if (!found)
        cout << "Khong co so dang 5^k (tra ve 0).\n";
    else
        cout << "Gia tri lon nhat dang 5^k: " << best << "\n";
    return 0;
}
