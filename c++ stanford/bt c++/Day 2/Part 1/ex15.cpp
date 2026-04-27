#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    char x, y;
    cout << "Nhap xau: ";
    getline(cin, s);
    cout << "Ky tu can thay (x): ";
    cin >> x;
    cout << "Ky tu thay the (y): ";
    cin >> y;

    int cnt = (int)count(s.begin(), s.end(), x);
    replace(s.begin(), s.end(), x, y);

    cout << "Xau moi: " << s << "\n";
    cout << "Da thay " << cnt << " ky tu '" << x << "' -> '" << y << "'\n";
    return 0;
}
