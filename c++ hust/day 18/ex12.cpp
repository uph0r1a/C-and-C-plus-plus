#include <iostream>
using namespace std;

int Ackermann(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (n == 0)
    {
        return Ackermann(m - 1, 1);
    }
    else
    {
        return Ackermann(m - 1, Ackermann(m, n - 1));
    }
}

int main(int argc, char const *argv[])
{
    cout << "A(0, 0): " << Ackermann(0, 0) << endl
         << "A(0, 1): " << Ackermann(0, 1) << endl
         << "A(1, 1): " << Ackermann(1, 1) << endl
         << "A(1, 2): " << Ackermann(1, 2) << endl
         << "A(1, 3): " << Ackermann(1, 3) << endl
         << "A(2, 2): " << Ackermann(2, 2) << endl
         << "A(3, 2): " << Ackermann(3, 2) << endl;
    return 0;
}
