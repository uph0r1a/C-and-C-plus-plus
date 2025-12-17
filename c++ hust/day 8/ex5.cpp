#include <iostream>
using namespace std;

int doSomething(int *x, int *y)
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}

int main(int argc, char const *argv[])
{
    int x = 2, y = 3;
    cout << doSomething(&x, &y) << endl;
    return 0;
}
