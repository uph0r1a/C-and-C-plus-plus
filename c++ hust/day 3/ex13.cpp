#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int purchased_book;
    cout << "Enter the number of books that you have purchased this month";
    cin >> purchased_book;
    if (purchased_book <= 0)
    {
        cout << "Earns 0 points";
    }
    else if (purchased_book == 1)
    {
        cout << "Earns 5 points";
    }
    else if (purchased_book == 2)
    {
        cout << "Earns 15 points";
    }
    else if (purchased_book == 3)
    {
        cout << "Earns 30 points";
    }
    else
    {
        cout << "Earns 60 points";
    }

    return 0;
}
