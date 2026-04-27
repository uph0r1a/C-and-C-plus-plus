#include <iostream>
#include <numeric>
using namespace std;

int main(int argc, char const *argv[])
{
    const int MAX = 100;
    double arr[MAX];
    int N = 0;

    while (1)
    {
        cout << "Nhap so phan tu (1 - " << MAX << "): ";
        if (!(cin >> N))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (N >= 1 && N <= MAX)
            break;
        cout << "  [!] N phai nam trong [1, " << MAX << "]. Nhap lai.\n";
    }

    cout << "Nhap " << N << " phan tu:\n";
    for (int i = 0; i < N; i++)
    {
        cout << "  so " << (i + 1) << ": ";
        cin >> arr[i];
    }

    double tong = accumulate(arr, arr + N, 0.0);
    cout << "Tong cua day: " << tong << "\n";

    return 0;
}