#include <iostream>
#include <vector>
using namespace std;

void inMang(const string &ten, const vector<int> &v)
{
    cout << ten << ": ";
    if (v.empty())
    {
        cout << "(rong)";
    }
    else
        for (int x : v)
            cout << x << " ";
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap n (>= 1): ";
        cin >> n;
    } while (n < 1);

    vector<int> a(n), am, duong;
    for (int i = 0; i < n; i++)
    {
        cout << "  a[" << (i + 1) << "]: ";
        cin >> a[i];
        if (a[i] < 0)
            am.push_back(a[i]);
        else if (a[i] > 0)
            duong.push_back(a[i]);
    }

    inMang("Mang goc", a);
    inMang("Mang am", am);
    inMang("Mang duong", duong);
    return 0;
}