#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "=== CAP PHAT BIEN DON ===\n";
    int *pr = new int;
    *pr = 8;
    cout << "Gia tri *pr = " << *pr << "\n";
    delete pr;
    pr = nullptr;
    cout << "Da giai phong bo nho cua pr.\n\n";

    cout << "=== CAP PHAT MANG CO DINH (2 phan tu) ===\n";
    int *p2 = new int[2];
    p2[0] = 2;
    p2[1] = 5;
    for (int i = 0; i < 2; i++)
        cout << "p2[" << i << "] = " << p2[i] << "\n";
    delete[] p2;
    p2 = nullptr;
    cout << "Da giai phong bo nho cua p2.\n\n";

    cout << "=== CAP PHAT MANG DONG ===\n";
    int n = 0;
    cout << "Nhap so phan tu n: ";
    cin >> n;

    float *p3 = new float[n];

    cout << "Nhap gia tri cac phan tu:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "p3[" << i << "] = ";
        cin >> p3[i];
    }

    cout << "Cac phan tu vua nhap: ";
    for (int i = 0; i < n; i++)
        cout << p3[i] << "  ";
    cout << "\n";

    delete[] p3;
    p3 = nullptr;
    cout << "Da giai phong bo nho cua p3.\n";

    return 0;
}
