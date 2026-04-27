#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap so tu nhien n (>= 1): ";
        cin >> n;
    } while (n < 1);

    vector<int> uoc;
    for (int i = 1; (long long)i * i <= n; i++)
    {
        if (n % i == 0)
        {
            uoc.push_back(i);
            if (i != n / i)
                uoc.push_back(n / i);
        }
    }
    sort(uoc.begin(), uoc.end());

    long long tong = 0;
    cout << "Cac uoc cua " << n << ": ";
    for (int u : uoc)
    {
        cout << u << " ";
        tong += u;
    }
    cout << "\nTong cac uoc: " << tong << "\n";

    return 0;
}
