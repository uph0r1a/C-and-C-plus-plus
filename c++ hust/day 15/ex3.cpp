#include <iostream>
using namespace std;

template <typename T>
T minimum(T a, T b)
{
    return a < b ? a : b;
}
template <typename T>
T maximum(T a, T b)
{
    return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
    int a = 2, b = 3;
    cout << "Min: " << minimum<int>(a, b) << endl
         << "Max: " << maximum<int>(a, b) << endl;

    float c = 2.5, d = 2.7;
    cout << "Min: " << minimum<float>(c, d) << endl
         << "Max: " << maximum<float>(c, d) << endl;

    double e = 1.3, f = 1.2;
    cout << "Min: " << minimum<double>(e, f) << endl
         << "Max: " << maximum<double>(e, f) << endl;

    return 0;
}
