#include <stdio.h>

void inputArray(int arr[], int so)
{
    for (int i = 0; i < so; i++)
    {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int so)
{
    for (int i = 0; i < so; i++)
    {
        printf("%d", arr[i]);
    }
}

void duyetmang(int arr[])
{
    int so;
    printf("Muon nhap bao so: ");
    scanf("%d", &so);
    inputArray(arr, so);
    printArray(arr, so);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
