#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float N[] = {9, 1, 2, 8, 7, 3, 4, 6, 5}, min;
    int minIndex;

    for (int i = 0; i < sizeof(N) / sizeof(N[0]); i++)
    {
        if (i == 0)
        {
            min = N[i];
            continue;
        }
        if (N[i] < min)
        {
            min = N[i];
            minIndex = i;
        }
    }

    cout << "Index of the elements with the minimum value: " << minIndex << endl;

    return 0;
}
