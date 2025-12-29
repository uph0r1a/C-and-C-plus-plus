#include <iostream>
using namespace std;

int *ReverseArray(int arr[], int size)
{
    int *reverse = new int[size];

    for (int i = 0; i < size; i++)
    {
        reverse[i] = arr[size - i - 1];
    }
    return reverse;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, arrSize = sizeof(arr) / sizeof(arr[0]);
    int *reverse = ReverseArray(arr, arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        cout << reverse[i] << "\t";
    }
    cout << endl;

    delete[] reverse;
    return 0;
}
