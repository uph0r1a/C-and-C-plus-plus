#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, K;
    do
    {
        cout << "Nhap n (>= 1): ";
        cin >> n;
    } while (n < 1);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << (i + 1) << "]: ";
        cin >> a[i];
    }
    cout << "Nhap K: ";
    cin >> K;

    auto itMax = max_element(a.begin(), a.end());
    auto itMin = min_element(a.begin(), a.end());
    cout << "\nMax = " << *itMax << " tai vi tri " << (itMax - a.begin() + 1) << "\n";
    cout << "Min = " << *itMin << " tai vi tri " << (itMin - a.begin() + 1) << "\n";

    long long sqSum = 0;
    for (int i = 1; i < n; i += 2)
        sqSum += (long long)a[i] * a[i];
    cout << "Tong BP vi tri chan (2,4,...) = " << sqSum << "\n";

    cout << "Vi tri cua K=" << K << ": ";
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == K)
        {
            cout << (i + 1) << " ";
            cnt++;
        }
    cout << (cnt == 0 ? "(khong co)" : "") << "\n";
    cout << "So lan xuat hien: " << cnt << "\n";

    sort(a.begin(), a.end());
    cout << "Tang dan: ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";

    sort(a.begin(), a.end(), greater<int>());
    cout << "Giam dan: ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";

    return 0;
}
