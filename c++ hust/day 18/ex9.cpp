#include <iostream>
#include <string>
using namespace std;

void reverser(string str)
{
    if (str.empty())
    {
        return;
    }

    cout << str.back();
    str.pop_back();
    reverser(str);
}

int main(int argc, char const *argv[])
{
    string str = "abcd";
    reverser(str);

    return 0;
}