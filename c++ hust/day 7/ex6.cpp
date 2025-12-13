#include <iostream>
#include <string>
using namespace std;

void selectionSort(string arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (static_cast<unsigned char>(arr[j][0]) <
                static_cast<unsigned char>(arr[min][0]))
            {
                min = j;
            }
        }

        string temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
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

    return 0;
}
