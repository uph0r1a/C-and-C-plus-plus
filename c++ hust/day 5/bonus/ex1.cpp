#include <iostream>
using namespace std;

int Fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int fibonacci;
    cout << "Enter n: ";
    while (1)
    {
        cin >> n;
        if (n >= 0)
        {
            break;
        }
        cout << "n cannot be negative\nRe-enter n: ";
    }

    fibonacci = Fibonacci(n);

    cout << "The " << n << "-th Fibonacci number is: " << fibonacci<<endl;
    return 0;
}
