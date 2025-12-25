#include <iostream>
using namespace std;

int sumDivisors(int n)
{
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n = 1000;
    cout << "Sum of positive divisor: " << sumDivisors(n) << endl;
    return 0;
}
