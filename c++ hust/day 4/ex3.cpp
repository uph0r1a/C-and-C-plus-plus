#include <iostream>
using namespace std;
#define CURRENT_YEAR 2025

int main(int argc, char const *argv[])
{
    float level = 0;
    for (int i = 0; i <= 25; i++)
    {
        level += 1.5;
        cout << CURRENT_YEAR << ": " << level << " millimeters\n";
    }

    return 0;
}
