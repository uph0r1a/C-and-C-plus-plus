#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    const string str = "Cong ty Stanford - Dao tao va phat trien cong nghe";
    cout << "Chuoi goc: " << str << "\n\n";

    vector<string> words;
    istringstream iss(str);
    string word;
    while (iss >> word)
        words.push_back(word);

    for (int i = 0; i < (int)words.size(); i++)
        cout << "a[" << i << "] = " << words[i] << "\n";

    return 0;
}
