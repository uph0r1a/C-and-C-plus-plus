#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string color1, color2;
loop1:
    cout << "Enter the names of primary colors 1 to mix: ";
    getline(cin, color1);
    if (color1 != "red" && color1 != "blue" && color1 != "yellow")
    {
        cout << "Error" << "\n";
        goto loop1;
    }
loop2:
    cout << "Enter the names of primary colors 2 to mix: ";
    getline(cin, color2);
    if (color2 != "red" && color2 != "blue" && color2 != "yellow")
    {
        cout << "Error" << "\n";
        goto loop2;
    }

    if ((color1 == "red" && color2 == "blue") || (color1 == "blue" && color2 == "red"))
    {
        cout << "Purple";
    }
    else if ((color1 == "red" && color2 == "yellow") || (color1 == "yellow" && color2 == "red"))
    {
        cout << "Orange";
    }
    else if (color1 == color2)
    {
        cout << color1;
    }
    else
    {
        cout << "Green";
    }

    return 0;
}
