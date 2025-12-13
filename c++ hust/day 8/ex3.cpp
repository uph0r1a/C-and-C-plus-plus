#include <iostream>
using namespace std;

int *Sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

float Average(int arr[], int size)
{
    int sum = 0, min = arr[0];
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return (static_cast<float>(sum) - static_cast<float>(min)) / static_cast<float>(size);
}

int main(int argc, char const *argv[])
{
    int size;
    cout << "Enter a array size: ";
    while (1)
    {
        cin >> size;
        if (size >= 0)
        {
            break;
        }
        cout << "Array size cannot be negative\nRe-enter a array size: ";
    }

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter score number " << i + 1 << ": ";
        while (1)
        {
            cin >> arr[i];
            if (arr[i] >= 0)
            {
                break;
            }
            cout << "Test score cannot be negative\nEnter score number " << i + 1 << ": ";
        }
    }

    arr = Sort(arr, size);
    float average = Average(arr, size);

    cout << "Sort score array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    cout << "Average score: " << average << endl;

    return 0;
}
