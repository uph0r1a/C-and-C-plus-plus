#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> N = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int j = N.size() - 1;

    for (int i = 0; i < j; i++)
    {
        int temp = N[j];
        N[j] = N[i];
        N[i] = temp;
        j--;
    }

    for (int i = 0; i < N.size(); i++)
    {
        cout << N[i] << "\t";
    }

    return 0;
}
