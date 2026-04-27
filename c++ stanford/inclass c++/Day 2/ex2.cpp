#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const int MAX = 20;
    float arr[MAX];
    int N = 0;

    do
    {
        cout << "Nhap so phan tu N (1 - " << MAX << "): ";
        cin >> N;
        if (N < 1 || N > MAX)
            cout << "N phai nam trong khoang 1 den " << MAX << ". Nhap lai.\n";
    } while (N < 1 || N > MAX);

    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < N; i++)
    {
        cout << "  arr[" << i << "] = ";
        cin >> arr[i];
    }

    float x = 0;
    cout << "\nNhap gia tri can tim x = ";
    cin >> x;

    bool timThay = false;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == x)
        {
            cout << "Phan tu " << x << " xuat hien dau tien tai vi tri: " << i + 1 << "\n";
            timThay = true;
            break;
        }
    }

    if (!timThay)
        cout << "Khong tim thay phan tu " << x << " trong day.\n";

    return 0;
}
