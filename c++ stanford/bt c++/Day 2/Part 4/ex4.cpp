#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string fullName;
    cout << "Nhap ho ten: ";
    getline(cin, fullName);

    istringstream iss(fullName);
    vector<string> parts;
    string w;
    while (iss >> w)
        parts.push_back(w);

    if (parts.empty())
    {
        cout << "Chuoi rong!\n";
        return 1;
    }

    string ho = parts.front();
    string ten = parts.size() > 1 ? parts.back() : "";
    string tenDem = "";
    for (int i = 1; i < (int)parts.size() - 1; i++)
        tenDem += (tenDem.empty() ? "" : " ") + parts[i];

    cout << "Ho: " << ho << "\n";
    cout << "Ten dem: " << (tenDem.empty() ? "(khong co)" : tenDem) << "\n";
    cout << "Ten: " << (ten.empty() ? "(khong co)" : ten) << "\n";
    return 0;
}
