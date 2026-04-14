#include <iostream>
using namespace std;

template <typename T>
T absolute(T a)
{
    if (a >= 0)
    {
        return a;
    }
    return a - (2 * a);
}

int main(int argc, char const *argv[])
{
    int a = -5;
    cout << "Absolute: " << absolute<int>(a) << endl;
    return 0;
}
