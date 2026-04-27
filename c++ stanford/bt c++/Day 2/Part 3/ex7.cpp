#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap n (>= 1): ";
        cin >> n;
    } while (n < 1);
    int x, y;
    do
    {
        cout << "Nhap x: ";
        cin >> x;
        cout << "Nhap y: ";
        cin >> y;
    } while (x > y);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "  a[" << i + 1 << "]: ";
        cin >> a[i];
    }

    int idx = -1;
    for (int i = 0; i < n; i++)
        if (a[i] >= x && a[i] <= y)
        {
            idx = i;
            break;
        }

    if (idx == -1)
        cout << "Khong co phan tu nao trong [" << x << ", " << y << "].\n";
    else
        cout << "Phan tu dau tien trong [" << x << ", " << y << "]: "
             << a[idx] << " (vi tri " << idx + 1 << ")\n";
    return 0;
}
