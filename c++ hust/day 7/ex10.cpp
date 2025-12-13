#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &arr)
{
    for (int x : arr)
        cout << x << "\t";
    cout << endl;
}

vector<int> bubbleSort(vector<int> &arr)
{
    cout << "\n--- Bubble Sort ---" << endl;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        cout << "After pass " << i + 1 << ": ";
        printArray(arr);
    }

    return arr;
}

vector<int> selectionSort(vector<int> &arr)
{
    cout << "\n--- Selection Sort ---" << endl;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;

        cout << "After pass " << i + 1 << ": ";
        printArray(arr);
    }

    return arr;
}

int main(int argc, char const *argv[])
{
    vector<int> arr1 = {9, 8, 2, 1, 7, 3, 6, 4}, arr2 = {9, 8, 4, 3, 9, 8, 1, 2};

    cout << "Original Array 1: ";
    printArray(arr1);

    cout << "Original Array 2: ";
    printArray(arr2);

    bubbleSort(arr1);

    selectionSort(arr2);

    cout << "\nFinal Bubble Sorted Array: ";
    printArray(arr1);

    cout << "Final Selection Sorted Array: ";
    printArray(arr2);

    return 0;
}
