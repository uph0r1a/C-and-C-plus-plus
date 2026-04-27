#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    do
    {
        cout << "Nhap hai so tu nhien a va b (>= 0): ";
        cin >> a >> b;
    } while (a < 0 || b < 0);

    if (a < b)
        cout << "So thu nhat be hon so thu hai\n";
    else if (a > b)
        cout << "So thu nhat lon hon so thu hai\n";
    else
        cout << "Hai so bang nhau\n";
    return 0;
}
