#include <stdio.h>

void insertElement(int i, int n, int arr[])
{
    int so;
    printf("Muon nhap bao so: ");
    scanf("%d", &so);
    if (i < 0 || i >= so)
    {
        printf("i ko thuoc khoang cua arr\n");
        return;
    }

    for (int a = so; a > i; a--)
    {
        arr[a] = arr[a - 1];
    }
    arr[i] = n;

    so++;

    for (int b = 0; b < so; b++)
    {
        printf("%d\t", arr[b]);
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
