#include <iostream>
using namespace std;

int *arrayAllocate(int size)
{
    int *arr = new int[size];
    return arr;
}

int main(int argc, char const *argv[])
{
    int size;
    cout << "Enter a size: ";
    while (1)
    {
        cin >> size;
        if (size >= 0)
        {
            break;
        }
        cout << "Size must not be negative\nRe-enter a size: ";
    }

    int *arr = arrayAllocate(size);

    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
        cout << arr[i] << endl;
    }

    delete[] arr;

    return 0;
}