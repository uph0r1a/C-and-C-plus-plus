#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    if (a == 0)
    {
        cout << "No solution";
    }
    else
    {
        cout << "x = " << -b / a;
    }

    return 0;
}
