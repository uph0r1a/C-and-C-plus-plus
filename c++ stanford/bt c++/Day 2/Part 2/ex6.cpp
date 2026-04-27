#include <iostream>
#include <vector>
using namespace std;

bool doiXung(const vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n / 2; i++)
        if (a[i] != a[n - 1 - i])
            return false;
    return true;
}
bool tangDan(const vector<int> &a)
{
    for (int i = 0; i + 1 < (int)a.size(); i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}
bool giamDan(const vector<int> &a)
{
    for (int i = 0; i + 1 < (int)a.size(); i++)
        if (a[i] < a[i + 1])
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap n (>= 2): ";
        cin >> n;
    } while (n < 2);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "  a[" << (i + 1) << "]: ";
        cin >> a[i];
    }

    cout << "Doi xung: " << (doiXung(a) ? "Co" : "Khong") << "\n";
    if (tangDan(a))
        cout << "Thu tu: Tang dan\n";
    else if (giamDan(a))
        cout << "Thu tu: Giam dan\n";
    else
        cout << "Thu tu: Khong tang, khong giam\n";
    return 0;
}
