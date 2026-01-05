#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void Name_search()
{
    vector<string> boy, girl;

    ifstream f1("files/GirlNames.txt");
    ifstream f2("files/BoyNames.txt");

    if (!f1 || !f2)
    {
        cout << "Cannot open file";
        return;
    }
    string boyname, girlname;
    while (getline(f1, girlname), getline(f2, boyname))
    {
        girl.push_back(girlname);
        boy.push_back(boyname);
    }

    boyname = "";
    girlname = "";

    cout << "Enter a boy's name (Press enter to skip): ";
    getline(cin, boyname);

    cout << "Enter a girl's name (Press enter to skip): ";
    getline(cin, girlname);

    for (int i = 0; i < boy.size(); i++)
    {
        if (boyname.size() == 0)
        {
            break;
        }
        if (boyname == boy[i])
        {
            cout << "The boy name " << boyname << " were among the most popular." << endl;
            break;
        }
    }
    for (int i = 0; i < girl.size(); i++)
    {
        if (girlname.size() == 0)
        {
            break;
        }
        if (girlname == girl[i])
        {
            cout << "The girl name " << girlname << " were among the most popular." << endl;
            break;
        }
    }
    f1.close();
    f2.close();
}

int main(int argc, char const *argv[])
{
    Name_search();
    return 0;
}
