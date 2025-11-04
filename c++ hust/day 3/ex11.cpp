#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(0));
    int a = rand(), b = rand(), answer;
    cout << a << endl;
    cout << "+" << b << "\n";
    cout << "------" << endl;
    cout << "Enter the answer: ";
    cin >> answer;
    if (a + b == answer)
    {
        cout << "Congratulations";
    }
    else
    {
        cout << a + b;
    }

    return 0;
}
