#include <iostream>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<char, string> morse = {
        {'A', ".-"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."},

        {'0', "-----"},
        {'1', ".----"},
        {'2', "..---"},
        {'3', "...--"},
        {'4', "....-"},
        {'5', "....."},
        {'6', "-...."},
        {'7', "--..."},
        {'8', "---.."},
        {'9', "----."},

        {',', "--..--"},
        {'.', ".-.-.-"},
        {'?', "..--.."},
    };

    string text;
    cout << "Enter text: ";
    getline(cin, text);

    for (char c : text)
    {
        if (c == ' ')
        {
            cout << "/ ";
        }
        else
        {
            c = toupper(c);

            if (morse.find(c) != morse.end())
            {
                cout << morse[c] << " ";
            }
            else
            {
                cout << "? ";
            }
        }
    }
    return 0;
}
