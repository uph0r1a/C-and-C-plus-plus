#include <iostream>
#include <iomanip>
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

    cout << "\nMang vua nhap: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << "  ";
    cout << "\n";

    float tongDay = 0, tongDuong = 0, tongAm = 0;
    float tongViTriChan = 0, tongViTriLe = 0;

    for (int i = 0; i < N; i++)
    {
        tongDay += arr[i];

        if (arr[i] >= 0)
            tongDuong += arr[i];
        else
            tongAm += arr[i];

        if (i % 2 == 0)
            tongViTriChan += arr[i];
        else
            tongViTriLe += arr[i];
    }

    float trungBinh = tongDay / N;

    cout << fixed << setprecision(2);
    cout << "\n--- Ket qua ---\n";
    cout << "Tong day: " << tongDay << "\n";
    cout << "Trung binh day: " << trungBinh << "\n";
    cout << "Tong so duong: " << tongDuong << "\n";
    cout << "Tong so am: " << tongAm << "\n";
    cout << "Tong vi tri chan: " << tongViTriChan << "\n";
    cout << "Tong vi tri le: " << tongViTriLe << "\n";

    return 0;
}
