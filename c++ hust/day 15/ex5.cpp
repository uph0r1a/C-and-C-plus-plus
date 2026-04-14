#include <iostream>
using namespace std;

template <typename T>
T total(int n)
{
    T sum = 0, value;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        sum += value;
    }

    return sum;
}

int main(int argc, char const *argv[])
{
    int n = 3;

    cout << "Total: " << total<int>(n) << endl;
    return 0;
}
