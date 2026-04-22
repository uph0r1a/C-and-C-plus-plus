#include <iostream>
using namespace std;

void sign(int n)
{
    if (n <= 0)
    {
        return;
    }

    cout << "No Parking\n";
    sign(n - 1);
}

int main(int argc, char const *argv[])
{
    sign(5);
    return 0;
}
