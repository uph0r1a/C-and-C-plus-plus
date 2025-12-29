#include <iostream>
using namespace std;

int *Shifter(int arr[], int size)
{
    int *shifterArray = new int[size + 1];

    shifterArray[0] = 0;
    for (int i = 0; i < size; i++)
    {
        shifterArray[i + 1] = arr[i];
    }
    return shifterArray;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, arrSize = sizeof(arr) / sizeof(arr[0]);
    int *shifterArray = Shifter(arr, arrSize);

    for (int i = 0; i < arrSize + 1; i++)
    {
        cout << shifterArray[i] << "\t";
    }
    cout << endl;

    delete[] shifterArray;
    return 0;
}
