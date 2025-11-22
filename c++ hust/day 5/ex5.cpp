#include <iostream>
#include <cmath>
using namespace std;
#define g 9.8

float fallingDistance(float time)
{
    return 0.5 * g * pow(time, 2);
}

int main(int argc, char const *argv[])
{
    float distance;
    cout << "Time\t\tDistance\n";
    for (int i = 1; i <= 10; i++)
    {
        distance = fallingDistance(i);
        cout << i << "\t\t" << distance << endl;
    }

    return 0;
}
