#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

float ex(float x, int n)
{
    if (n == 0)
        return 1;
    return ex(x, n - 1) + pow(x, n) / factorial(n);
}

int main()
{
    int n = 2;
    float x = 2;
    cout << ex(x, n) << endl;
    return 0;
}
