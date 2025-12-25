#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> N = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 5};

    for (int i = 0; i < N.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (N[i] == N[j])
            {
                N.erase(N.begin() + i);
                i--;
                break;
            }
        }
    }

    for (int x : N)
    {
        cout << x << "\t";
    }
}
