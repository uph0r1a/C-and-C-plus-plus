#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream f("text.txt");
    string word, max = "";

    if (!f.is_open())
    {
        cout << "Cannot open file";
        return 1;
    }

    while (f >> word)
    {
        if (word.length() > max.length())
        {
            max = word;
        }
    }
    cout << "Longest word: " << max;
    f.close();
    return 0;
}
