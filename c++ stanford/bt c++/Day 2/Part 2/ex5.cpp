#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap n (1 <= n < 20): ";
        cin >> n;
    } while (n < 1 || n >= 20);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << (i + 1) << "]: ";
        cin >> a[i];
    }

    cout << "Mang goc: ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";

    bool found = false;
    for (int i = 0; i < n - 1; i++)
    {
        int tong = a[i] + a[i + 1];
        if (tong % 10 == 0)
        {
            cout << "Cap (" << a[i] << ", " << a[i + 1] << ") tai vi tri "
                 << (i + 1) << " va " << (i + 2) << " -> thay bang " << tong << "\n";
            a[i] = tong;
            a[i + 1] = tong;
            found = true;
            i++;
        }
    }
    if (!found)
        cout << "Khong co cap nao co tong chia het 10.\n";

    cout << "Mang ket qua: ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";
    return 0;
}
