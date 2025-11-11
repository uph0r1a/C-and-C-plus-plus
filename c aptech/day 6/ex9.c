#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[100], so;

    printf("Muon nhap bao so: ");
    scanf("%d", &so);

    for (int i = 0; i < so; i++)
    {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < so; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    return 0;
}