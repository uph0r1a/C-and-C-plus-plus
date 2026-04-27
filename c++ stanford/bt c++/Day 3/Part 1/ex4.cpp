#include <iostream>
using namespace std;

int ucln(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int uclnNhieuSo(int arr[], int n)
{
    int ketQua = arr[0];
    for (int i = 1; i < n; i++)
    {
        ketQua = ucln(ketQua, arr[i]);
    }
    return ketQua;
}

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    cout << "Nhap 4 so nguyen: ";
    cin >> a >> b >> c >> d;

    cout << endl;
    cout << "UCLN(" << a << ", " << b << ") = " << ucln(a, b) << endl;
    cout << "UCLN(" << a << ", " << b << ", " << c << ") = " << ucln(ucln(a, b), c) << endl;

    int arr[] = {a, b, c, d};
    int ketQua = uclnNhieuSo(arr, 4);
    cout << "UCLN(" << a << ", " << b << ", " << c << ", " << d << ") = " << ketQua << endl;

    return 0;
}
