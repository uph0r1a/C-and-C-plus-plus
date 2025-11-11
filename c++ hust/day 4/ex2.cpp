#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int count = 0;

    while (1)
    {
        cout << count << ": " << static_cast<char>(count) << "\t";
        count++;
        if (count == 127)
        {
            break;
        }
        if (count % 16 == 0)
        {
            cout << "\n";
        }
    }

    return 0;
}
