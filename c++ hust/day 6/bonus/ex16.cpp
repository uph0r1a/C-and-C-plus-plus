#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> N = {3, 2, 5, 4, 8, 6, 7, 9, 10, 1};

    for (int i = 0; i < N.size(); i++)
    {
        for (int j = 0; j < N.size() - i - 1; j++)
        {
            if (N[j] > N[j + 1])
            {
                int temp = N[j + 1];
                N[j + 1] = N[j];
                N[j] = temp;
            }
        }
    }

    for (int i = 0; i < N.size(); i++)
    {
        cout << N[i] << "\t";
    }

    return 0;
}
