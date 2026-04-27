#include <iostream>
#include <vector>
using namespace std;

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

    int d = a[1] - a[0];
    bool isCSC = true;
    for (int i = 2; i < n; i++)
        if (a[i] - a[i - 1] != d)
        {
            isCSC = false;
            break;
        }

    if (isCSC)
        cout << "La cap so cong voi cong sai d = " << d << "\n";
    else
        cout << "Khong phai cap so cong.\n";
    return 0;
}
