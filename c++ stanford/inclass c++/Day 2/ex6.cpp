#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitWords(const string &str, char delim = ' ')
{
    vector<string> words;
    string token;
    for (char ch : str)
    {
        if (ch == delim)
        {
            if (!token.empty())
            {
                words.push_back(token);
                token.clear();
            }
        }
        else
        {
            token += ch;
        }
    }
    if (!token.empty())
        words.push_back(token);
    return words;
}

int main(int argc, char const *argv[])
{
    string strCongTy = "Cong ty Stanford - Dao tao va phat trien cong nghe";

    cout << "Chuoi goc: " << strCongTy << "\n\n";

    vector<string> words = splitWords(strCongTy);

    cout << "Cac tu sau khi tach:\n";
    for (int i = 0; i < (int)words.size(); i++)
        cout << "  a[" << i << "] = " << words[i] << "\n";

    return 0;
}
