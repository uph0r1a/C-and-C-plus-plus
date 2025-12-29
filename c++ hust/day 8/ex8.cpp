#include <iostream>
using namespace std;

int findMode(int *arr, int size)
{
    int mode = -1;
    int maxCount = 1;

    for (int i = 0; i < size; i++)
    {
        int count = 1;

        for (int j = i + 1; j < size; j++)
        {
            if (*(arr + i) == *(arr + j))
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            mode = *(arr + i);
        }
    }

    return mode;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 2, 3, 4, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = findMode(arr, size);

    if (result == -1)
        cout << "The array has no mode." << endl;
    else
        cout << "The mode is: " << result << endl;

    return 0;
}
