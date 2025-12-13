#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> arr, int value)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        count++;
        if (value == arr[i])
        {
            break;
        }
    }
    return count;
}

int binarySearch(vector<int> arr, int value)
{
    int count = 0;
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        count++;
        int mid = (low + high) / 2;

        if (arr[mid] == value)
        {
            break;
        }
        else if (value < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return count;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                       11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int number;
    cout << "Enter a number: ";
    cin >> number;

    cout << "Linear search: " << linearSearch(arr, number) << endl;
    cout << "Binary search: " << binarySearch(arr, number) << endl;

    return 0;
}
