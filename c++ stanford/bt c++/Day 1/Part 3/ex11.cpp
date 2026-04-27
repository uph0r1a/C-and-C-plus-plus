#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double x, y;
    char op;

    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Toan tu (+  -  *  /): ";
    cin >> op;

    cout << fixed << setprecision(4);
    switch (op)
    {
    case '+':
        cout << x << " + " << y << " = " << x + y << "\n";
        break;
    case '-':
        cout << x << " - " << y << " = " << x - y << "\n";
        break;
    case '*':
        cout << x << " * " << y << " = " << x * y << "\n";
        break;
    case '/':
        if (y == 0)
            cout << "Khong chia duoc (y = 0)!\n";
        else
            cout << x << " / " << y << " = " << x / y << "\n";
        break;
    default:
        cout << "Toan tu khong hop le.\n";
    }

    return 0;
}
