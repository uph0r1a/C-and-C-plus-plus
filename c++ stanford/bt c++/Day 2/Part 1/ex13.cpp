#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cout << "Nhap xau: ";
    getline(cin, s);

    int cnt[10] = {};
    for (char c : s)
        if (c >= '0' && c <= '9')
            cnt[c - '0']++;

    cout << "Thong ke chu so:\n";
    for (int i = 0; i <= 9; i++)
        if (cnt[i] > 0)
            cout << "'" << i << "' xuat hien " << cnt[i] << " lan\n";
    return 0;
}
