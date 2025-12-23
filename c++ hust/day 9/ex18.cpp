#include <iostream>
#include <string>
#include <vector>
using namespace std;

void find(string namePhone[], int size)
{
    string search;
    vector<string> found;

    cout << "Enter name to search: ";
    while (1)
    {
        getline(cin, search);
        if (!search.empty())
        {
            break;
        }
        cout << "Name to search cannot be empty\nRe-enter name to search: ";
    }

    for (int i = 0; i < size; i++)
    {
        if (namePhone[i].find(search) != string::npos)
        {
            found.push_back(namePhone[i]);
        }
    }

    if (found.empty())
    {
        cout << "No name founded" << endl;
    }
    else
    {
        for (int i = 0; i < found.size(); i++)
        {
            cout << found[i] << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    string namePhone[] = {
        "Alejandra Cruz, 555-1223",
        "Joe Looney, 555-0097",
        "Geri Palmer, 555-8787",
        "Li Chen, 555-1212",
        "Holly Gaddis, 555-8878",
        "Sam Wiggins, 555-0998",
        "Bob Kain, 555-8712",
        "Tim Haynes, 555-7676",
        "Warren Gaddis, 555-9037",
        "Jean James, 555-4939",
        "Ron Palmer, 555-2783",
    };

    int size = sizeof(namePhone) / sizeof(namePhone[0]);

    find(namePhone, size);
    return 0;
}
