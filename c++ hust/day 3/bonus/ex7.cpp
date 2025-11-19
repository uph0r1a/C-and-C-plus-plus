#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float a, b, c, delta;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;

    if (a == 0)
    {
        if (b == 0)
        {
            cout << "No solution";
        }
        else
        {
            cout << "x = " << -c / b;
        }
    }
    else
    {
        delta = pow(b, 2) - 4 * a * c;
        if (delta > 0)
        {
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << ", x2 = " << (-b - sqrt(delta)) / (2 * a);
        }
        else if (delta == 0)
        {
            cout << "x = " << -b / 2 * a;
        }
        else
        {
            cout << "No solution";
        }
    }

    return 0;
}
