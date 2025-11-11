#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 2, 4, 6, 5, 9, 7, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}
