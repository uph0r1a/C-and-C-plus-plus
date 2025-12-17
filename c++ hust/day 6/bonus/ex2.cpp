#include <iostream>
#include <vector>
using namespace std;

int Even(vector<int> arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

int SumofOdd(vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 != 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {-5, 4, -9, 12, -2, 1, 2};

    cout << "Number of even number: " << Even(arr) << endl
         << "Sum of odd number: " << SumofOdd(arr) << endl;

    return 0;
}
