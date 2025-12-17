#include <iostream>
#include <vector>
using namespace std;

void ListNegative(vector<float> arr)
{
    cout << "Negative number: ";
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            cout << arr[i] << "\t";
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<float> arr = {-5, 4, -9, 12, -2, 1, 2};

    ListNegative(arr);

    return 0;
}
