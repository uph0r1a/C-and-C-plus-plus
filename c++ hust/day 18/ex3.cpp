#include <iostream>
using namespace std;

template <typename T>
T partition(T arr[], int start, int end)
{
    T pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i++;
    T temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    return i;
}

template <typename T>
void quicksort(T arr[], int start, int end)
{
    if (end <= start)
    {
        return;
    }

    int pivot = partition(arr, start, end);
    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1, end);
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 4, 2, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
