#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    int ans = (mx % 2 == 0) ? mx + 2 : mx + 1;
    if (mx < 0 && mx % 2 != 0)
        ans = mx + 1;
    if (mx < 0 && mx % 2 == 0)
        ans = mx + 2;

    cout << "Max mang = " << mx << "\n";
    cout << "So chan nho nhat lon hon max: " << ans << "\n";
    return 0;
}
