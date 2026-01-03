#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float N[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};

    for (int i = 0; i < sizeof(N) / sizeof(N[0]); i++)
    {
        for (int j = 0; j < sizeof(N) / sizeof(N[0]) - i - 1; j++)
        {
            if (N[j] < N[j + 1])
            {
                float temp = N[j];
                N[j] = N[j + 1];
                N[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < sizeof(N) / sizeof(N[0]); i++)
    {
        cout << N[i] << "\t";
    }
    cout << endl;

    return 0;
}
