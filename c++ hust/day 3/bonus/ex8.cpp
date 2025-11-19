#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float a, b, c;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;

    if (a + b > c && a + c > b && b + c > a)
    {
        cout << "a, b, c form a triangle";
    }
    else
    {
        cout << "a, b, c dont form a triangle";
    }

    return 0;
}
