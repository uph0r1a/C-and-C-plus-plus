#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    const int SIZE = 10;
    vector<int> a(SIZE);

    cout << "Nhap 10 phan tu:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "  a[" << (i + 1) << "]: ";
        cin >> a[i];
    }

    cout << "Goc: ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";

    sort(a.begin(), a.end());
    cout << "Tang: ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";

    sort(a.begin(), a.end(), greater<int>());
    cout << "Giam: ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";

    return 0;
}
