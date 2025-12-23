#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> seperated;
    string sentence, word;

    cout << "Enter a string: ";
    cin >> sentence;

    for (char c : sentence)
    {
        if (isupper(c) && !word.empty())
        {
            seperated.push_back(word);
            word.clear();
        }
        word += c;
    }

    if (!word.empty())
        seperated.push_back(word);

    for (int i = 0; i < seperated.size(); i++)
    {
        cout << seperated[i] << " ";
    }

    return 0;
}
