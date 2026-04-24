#include <iostream>
using namespace std;

int sumArray(int array[], int size)
{
    if (size < 0)
    {
        return 0;
    }
    return array[size] + sumArray(array, size - 1);
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << sumArray(arr, sizeof(arr) / sizeof(arr[0]) - 1);

    return 0;
}
