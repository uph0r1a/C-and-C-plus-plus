#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    cout << "Nhap 4 so nguyen: ";
    cin >> a >> b >> c >> d;

    int maxNum = max({a, b, c, d});
    int minNum = min({a, b, c, d});

    cout << "So lon nhat: " << maxNum << "\n";
    cout << "So nho nhat: " << minNum << "\n";
    return 0;
}
