#include <iostream>
#include <vector>
using namespace std;

void inMang(const vector<int> &a)
{
    for (int x : a)
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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << (i + 1) << "]: ";
        cin >> a[i];
    }
    cout << "Mang goc: ";
    inMang(a);

    int X, x;
    cout << "Nhap gia tri X can chen: ";
    cin >> X;
    int sz = (int)a.size();
    do
    {
        cout << "Nhap vi tri chen (1 den " << sz + 1 << "): ";
        cin >> x;
    } while (x < 1 || x > sz + 1);

    a.insert(a.begin() + (x - 1), X);
    cout << "Sau khi chen " << X << " vao vi tri " << x << ": ";
    inMang(a);

    int y;
    sz = (int)a.size();
    do
    {
        cout << "Nhap vi tri xoa (1 den " << sz << "): ";
        cin >> y;
    } while (y < 1 || y > sz);

    cout << "Xoa phan tu " << a[y - 1] << " tai vi tri " << y << "\n";
    a.erase(a.begin() + (y - 1));
    cout << "Mang cuoi cung: ";
    inMang(a);
    return 0;
}
