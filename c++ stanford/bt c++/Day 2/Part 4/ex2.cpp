#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cout << "Nhap chuoi: ";
    getline(cin, s);

    char target;
    cout << "Ky tu can dem: ";
    cin >> target;

    int cnt = (int)count(s.begin(), s.end(), target);

    cout << "So lan '" << target << "' xuat hien: " << cnt << "\n";

    cout << "Vi tri: ";
    for (int i = 0; i < (int)s.size(); i++)
        if (s[i] == target)
            cout << (i + 1) << " ";
    cout << "\n";
    return 0;
}
