#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap n (>= 1): ";
        cin >> n;
    } while (n < 1);
    vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "  a[" << i + 1 << "]: ";
        cin >> a[i];
    }

    auto [lo, hi] = minmax_element(a.begin(), a.end());
    cout << fixed << setprecision(4);
    cout << "Doan [a,b] = [" << *lo << ", " << *hi << "]\n";
    return 0;
}
