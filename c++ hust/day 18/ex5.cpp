#include <iostream>
using namespace std;

int multiplication(int x, int y)
{
    if (x == 0)
    {
        return 0;
    }

    if (x < 0)
    {
        return -multiplication(-x, y);
    }

    return y + multiplication(x - 1, y);
}

int main(int argc, char const *argv[])
{
    int x = -7, y = 4;

    cout << multiplication(x, y);

    return 0;
}
