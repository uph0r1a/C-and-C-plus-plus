#include <iostream>
using namespace std;

int findMax(int a, int b, int c)
{
    int max = a;

    if (b > c)
    {
        if (max > b)
        {
            return max;
        }
        return b;
    }

    if (max > c)
    {
        return max;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    int a = 2, b = 4, c = 1;

    cout << "Largest number: " << findMax(a, b, c) << endl;
    return 0;
}
