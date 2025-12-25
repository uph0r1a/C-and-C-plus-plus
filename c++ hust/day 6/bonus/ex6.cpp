#include <iostream>
using namespace std;

int findMin(int a, int b, int c)
{
    int min = a;

    if (b < c)
    {
        if (min < b)
        {
            return min;
        }
        return b;
    }

    if (min < c)
    {
        return min;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    int a = 2, b = 4, c = 1;

    cout << "Largest number: " << findMin(a, b, c) << endl;
    return 0;
}
