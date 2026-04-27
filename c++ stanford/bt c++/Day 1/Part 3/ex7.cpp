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

    long long tong = 0;
    for (int i = 1; i <= N; i += 2)
        tong += (long long)i * i;

    cout << "Tong binh phuong so le tu 1 den " << N << " = " << tong << "\n";
    return 0;
}
