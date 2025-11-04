#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(0));
    char answer;
    int a = rand(), b = rand();
    cout << a << endl;
    cout << "+" << b << "\n";
    cout << "------" << endl;
    cout << "Press y to check answer: ";
loop:
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        cout << a << endl;
        cout << "+" << b << endl;
        cout << "------" << endl;
        cout << a + b << endl;
    }
    else
    {
        cout << "Invalid input. Re-enter: ";
        goto loop;
    }

    return 0;
}
