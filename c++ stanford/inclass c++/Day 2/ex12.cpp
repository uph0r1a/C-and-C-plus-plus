#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    const int MAX = 20;
    float arr[MAX][MAX];
    int m = 0, n = 0;

    do
    {
        cout << "Nhap so dong m (1 - " << MAX << "): ";
        cin >> m;
        cout << "Nhap so cot  n (1 - " << MAX << "): ";
        cin >> n;
        if (m < 1 || m > MAX || n < 1 || n > MAX)
            cout << "m va n phai nam trong khoang 1 den " << MAX << ". Nhap lai.\n";
    } while (m < 1 || m > MAX || n < 1 || n > MAX);

    cout << "Nhap gia tri cho cac phan tu:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "  arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }

    cout << "\nMang " << m << "x" << n << ":\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(8) << arr[i][j];
        cout << "\n";
    }

    return 0;
}
