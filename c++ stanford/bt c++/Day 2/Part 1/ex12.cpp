#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cout << "Nhap xau: ";
    getline(cin, s);

    string rev = s;
    reverse(rev.begin(), rev.end());

    cout << "Goc: " << s << "\n";
    cout << "Dao nguoc: " << rev << "\n";
    return 0;
}
