#include <iostream>
#include <vector>
using namespace std;

int LessThanK(vector<float> n, float k)
{
    int count = 0;
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] < k)
        {
            count++;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    vector<float> n = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float k = 5;
    cout << "Number of element that less than k: " << LessThanK(n, k) << endl;
    return 0;
}
