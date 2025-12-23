#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
    char character;
    int upperCaseCount = 0, lowerCaseCount = 0, digitsCount = 0;

    ifstream f("text.txt");

    if (!f)
    {
        cout << "Cannot open file" << endl;
        return 1;
    }

    while (f.get(character))
    {
        if (isupper(character))
        {
            upperCaseCount++;
        }
        else if (islower(character))
        {
            lowerCaseCount++;
        }
        else if (isdigit(character))
        {
            digitsCount++;
        }
    }

    cout << "The number of uppercase letters in the file: " << upperCaseCount << endl
         << "The number of lowercase letters in the file: " << lowerCaseCount << endl
         << "The number of digits in the file: " << digitsCount << endl;

    f.close();

    return 0;
}
