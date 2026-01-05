#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayJoke(const string &filename)
{
    fstream f(filename, ios::in);
    if (!f)
    {
        cout << "Cannot open " << filename << endl;
        return;
    }

    string line;
    cout << "Joke:\n";
    while (getline(f, line))
    {
        cout << line << endl;
    }

    f.close();
}

void displayPunchline(const string &filename)
{
    fstream f(filename, ios::in | ios::binary);
    if (!f)
    {
        cout << "Cannot open " << filename << endl;
        return;
    }

    f.seekg(0, ios::end);
    std::streamoff size = f.tellg();

    if (size == 0)
    {
        cout << "Punchline file is empty" << endl;
        f.close();
        return;
    }

    char ch;
    std::streamoff pos = size - 1;

    while (pos >= 0)
    {
        f.seekg(pos);
        f.get(ch);
        if (ch == '\n')
        {
            pos++;
            break;
        }
        pos--;
    }

    if (pos < 0)
        pos = 0;

    f.seekg(pos);
    string lastLine;
    getline(f, lastLine);

    cout << "Punch line:\n"
         << lastLine << endl;

    f.close();
}

int main(int argc, char const *argv[])
{
    displayJoke("files/joke.txt");
    displayPunchline("files/punchline.txt");
    return 0;
}
