#include <iostream>
#include <vector>
using namespace std;

int bubbleSort(vector<int> &arr)
{
    cout << "\n--- Bubble Sort ---" << endl;
    int count = 0;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            count++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return count;
}

int selectionSort(vector<int> &arr)
{
    cout << "\n--- Selection Sort ---" << endl;
    int count = 0;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            count++;

            if (arr[j] < arr[min])
                min = j;
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    return count;
}

int main(int argc, char const *argv[])
{
    vector<int> arr1 = {57, 13, 89, 42, 6, 74, 28, 91, 3, 66, 17, 50, 8, 35, 99, 21, 47, 62, 14, 83}, arr2 = {72, 5, 33, 88, 11, 64, 29, 97, 41, 16, 53, 7, 84, 22, 90, 38, 12, 69, 25, 59};

    cout << "Bubble Sort Comparisons: " << bubbleSort(arr1) << endl;
    cout << "Selection Sort Comparisons: " << selectionSort(arr2) << endl;

    return 0;
}
