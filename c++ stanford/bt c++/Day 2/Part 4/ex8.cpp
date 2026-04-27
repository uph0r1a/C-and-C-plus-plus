#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cout << "Nhap chuoi: ";
    getline(cin, s);

    string w;
    vector<string> longest;
    size_t maxLen = 0;
    istringstream iss(s);

    while (iss >> w)
    {
        if (w.size() > maxLen)
        {
            maxLen = w.size();
            longest = {w};
        }
        else if (w.size() == maxLen)
            longest.push_back(w);
    }

    if (maxLen == 0)
    {
        cout << "Chuoi rong.\n";
        return 0;
    }

    cout << "Tu dai nhat (" << maxLen << " ky tu):\n";
    for (const auto &lw : longest)
        cout << "  " << lw << "\n";
    return 0;
}
