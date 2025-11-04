#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    if (a > b)
    {
        cout << b << " is smaller and " << a << " is larger";
    }
    else
    {
        cout << a << " is smaller and " << b << " is larger";
    }

    return 0;
}
