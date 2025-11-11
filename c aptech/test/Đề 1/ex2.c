#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[10];

    printf("Enter 10 integers: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Reversed Array: ");

    for (int i = 9; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}