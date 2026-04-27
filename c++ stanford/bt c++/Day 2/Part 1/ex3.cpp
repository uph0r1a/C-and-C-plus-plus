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

    vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << (i + 1) << "]: ";
        cin >> a[i];
    }

    auto itMax = max_element(a.begin(), a.end());
    auto itMin = min_element(a.begin(), a.end());

    cout << "Max = " << *itMax << " tai vi tri " << (itMax - a.begin() + 1) << "\n";
    cout << "Min = " << *itMin << " tai vi tri " << (itMin - a.begin() + 1) << "\n";
    return 0;
}
