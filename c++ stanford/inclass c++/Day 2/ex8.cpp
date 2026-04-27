#include <iostream>
#include <cmath>
using namespace std;

bool laSoNguyenTo(int n)
{
    if (n < 2)
        return false;
    for (int i = 2, lim = (int)sqrt((double)n); i <= lim; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    const int MAX = 20;
    int arr[MAX], N = 0;

    do
    {
        cout << "Nhap so phan tu N (1 - " << MAX - 1 << "): ";
        cin >> N;
        if (N < 1 || N >= MAX)
            cout << "N phai nam trong khoang 1 den " << MAX - 1 << ". Nhap lai.\n";
    } while (N < 1 || N >= MAX);

    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < N; i++)
    {
        cout << "  arr[" << i << "] = ";
        cin >> arr[i];
    }

    int tongSNT = 0;
    bool coSNT = false;

    cout << "\nCac so nguyen to trong day: ";
    for (int i = 0; i < N; i++)
    {
        if (laSoNguyenTo(arr[i]))
        {
            cout << arr[i] << "  ";
            tongSNT += arr[i];
            coSNT = true;
        }
    }

    if (!coSNT)
        cout << "(khong co)";
    cout << "\nTong cac so nguyen to: " << tongSNT << "\n";

    return 0;
}
