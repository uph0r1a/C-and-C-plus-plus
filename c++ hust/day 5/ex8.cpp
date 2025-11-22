#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void coinToss()
{
    srand(time(nullptr));

    int a = rand();

    if (a % 2 == 0)
    {
        cout << "Tails\n";
    }
    else
    {
        cout << "Heads\n";
    }
}

int main(int argc, char const *argv[])
{
    coinToss();
    return 0;
}
