#include <iostream>
using namespace std;

void Larger_than_n(int arr[], int size, float n)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > n)
        {
            cout << arr[i] << "\t";
        }
    }
}

int main(int argc, char const *argv[])
{

    int size;
    float n;

    cout << "Enter the size of the array: ";
    while (1)
    {
        cin >> size;
        if (size >= 0)
        {
            break;
        }
        cout << "Size cannot be negative\nRe-enter the size of the array: ";
    }

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter array element number " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Enter n: ";
    cin >> n;

    Larger_than_n(arr, size, n);
    return 0;
}
