#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

string tenCuoi(const string &s)
{
    istringstream iss(s);
    string w, last;
    while (iss >> w)
        last = w;
    return last;
}

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap so hoc sinh (1-10): ";
        cin >> n;
    } while (n < 1 || n > 10);
    cin.ignore();

    vector<string> names(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Ten HS " << (i + 1) << ": ";
        getline(cin, names[i]);
    }

    sort(names.begin(), names.end(), [](const string &a, const string &b)
         {
        string ta = tenCuoi(a), tb = tenCuoi(b);
        return ta != tb ? ta < tb : a < b; });

    cout << "\nDanh sach sap xep theo ten:\n";
    for (int i = 0; i < n; i++)
        cout << " " << (i + 1) << ". " << names[i] << "\n";
    return 0;
}
