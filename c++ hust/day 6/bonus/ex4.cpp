#include <iostream>
#include <vector>
using namespace std;

float MostFrequent(vector<float> &arr)
{
    int maxcount = 0;
    float result;
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxcount || (count == maxcount && arr[i] > result))
        {
            maxcount = count;
            result = arr[i];
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<float> arr = {1.1, 1.1, 1.1, 2, 3, -3};
    cout << "Most frequent number: " << MostFrequent(arr) << endl;
    return 0;
}
