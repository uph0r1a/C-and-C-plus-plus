#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int burned = 0;
    for (int i = 0; i <= 30; i++)
    {
        burned += 3.6;
        if (i % 5 == 0 && i != 0)
        {
            cout << "The number of calories burned after " << i << " minutes: " << burned << " calories\n";
        }
    }

    return 0;
}
