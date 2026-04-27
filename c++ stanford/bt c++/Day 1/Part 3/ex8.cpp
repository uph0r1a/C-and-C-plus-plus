#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    do
    {
        cout << "Nhap N (>= 1): ";
        cin >> N;
    } while (N < 1);

    int cntAm = 0, cntDuong = 0, cntKhong = 0;
    long long tongAm = 0, tongDuong = 0;

    for (int i = 1; i <= N; i++)
    {
        int x;
        cout << "So thu " << i << ": ";
        cin >> x;
        if (x < 0)
        {
            cntAm++;
            tongAm += x;
        }
        else if (x > 0)
        {
            cntDuong++;
            tongDuong += x;
        }
        else
            cntKhong++;
    }

    cout << "\nSo am: " << cntAm << " so,  tong = " << tongAm << "\n";
    cout << "So duong: " << cntDuong << " so,  tong = " << tongDuong << "\n";
    cout << "So khong: " << cntKhong << " so\n";

    return 0;
}
