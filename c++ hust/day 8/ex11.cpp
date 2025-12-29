#include <iostream>
using namespace std;

int *Expander(int arr[], int size)
{
    int *expandArray = new int[size * 2];

    for (int i = 0; i < size; i++)
    {
        expandArray[i] = arr[i];
    }

    for (int i = size; i < size * 2; i++)
    {
        expandArray[i] = 0;
    }

    return expandArray;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, arrSize = sizeof(arr) / sizeof(arr[0]);
    int *expandArray = Expander(arr, arrSize);

    for (int i = 0; i < arrSize * 2; i++)
    {
        cout << expandArray[i] << "\t";
    }
    cout << endl;

    delete[] expandArray;
    return 0;
}
