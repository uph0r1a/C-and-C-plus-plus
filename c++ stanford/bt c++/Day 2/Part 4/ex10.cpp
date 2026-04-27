#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    const int N = 9;

    cout << "   |";
    for (int j = 1; j <= N; j++)
        cout << setw(4) << j;
    cout << "\n"
         << string(4 + N * 4, '-') << "\n";

    for (int i = 1; i <= N; i++)
    {
        cout << setw(2) << i << " |";
        for (int j = 1; j <= N; j++)
            cout << setw(4) << i * j;
        cout << "\n";
    }
    return 0;
}
