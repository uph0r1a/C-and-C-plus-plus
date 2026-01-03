#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int N[] = {2, 1, 8, 9, 7, 3, 6, 4, 5};

    for (int i = 0; i < sizeof(N) / sizeof(N[0]); i++)
    {
        if (N[i] % N[0] == 0)
        {
            cout << N[i] << "\t";
        }
    }
    cout << endl;

    return 0;
}
