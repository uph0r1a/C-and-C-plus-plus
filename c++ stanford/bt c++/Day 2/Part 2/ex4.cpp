#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, x, y;
    do
    {
        cout << "Nhap n (>= 1): ";
        cin >> n;
    } while (n < 1);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "  a[" << (i + 1) << "]: ";
        cin >> a[i];
    }
    cout << "Nhap x (can tim): ";
    cin >> x;
    cout << "Nhap y (thay the): ";
    cin >> y;

    cout << "Vi tri cua " << x << ": ";
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == x)
        {
            cout << (i + 1) << " ";
            cnt++;
        }
    cout << (cnt == 0 ? "(khong co)" : "") << "\n";

    replace(a.begin(), a.end(), x, y);

    cout << "Mang sau thay the: ";
    for (int v : a)
        cout << v << " ";
    cout << "\n";
    return 0;
}
