#include <iostream>
#include <string>
using namespace std;

string toPigLatin(const string &word)
{
    if (word.length() == 0)
        return word;
    return word.substr(1) + word[0] + "ay";
}

int main(int argc, char const *argv[])
{
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string pigLatinSentence = "";
    string word = "";

    for (size_t i = 0; i <= sentence.length(); i++)
    {
        if (i == sentence.length() || sentence[i] == ' ')
        {
            pigLatinSentence += toPigLatin(word);
            if (i != sentence.length())
                pigLatinSentence += ' ';
            word = "";
        }
        else
        {
            word += sentence[i];
        }
    }

    cout << "Pig Latin: " << pigLatinSentence << endl;
    return 0;
}
