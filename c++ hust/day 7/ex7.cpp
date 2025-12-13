#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void selectionSort(string arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

bool binarySearch(string arr[], int size, const string &search)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == search)
            return true;
        else if (arr[mid] < search)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {
        "Collins, Bill", "Smith, Bart", "Allen, Jim",
        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill",
        "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
        "James, Jean", "Weaver, Jim", "Pore, Bob",
        "Rutherford, Greg", "Javens, Renee",
        "Harrison, Rose", "Setzer, Cathy",
        "Pike, Gordon", "Holland, Beth"};

    selectionSort(names, NUM_NAMES);

    for (int i = 0; i < NUM_NAMES; i++)
    {
        cout << names[i] << endl;
    }

    string searchName;

    cout << "Enter a name to search: ";
    getline(cin, searchName);

    if (binarySearch(names, NUM_NAMES, searchName))
        cout << searchName << " found!" << endl;
    else
        cout << searchName << " not found." << endl;

    return 0;
}
