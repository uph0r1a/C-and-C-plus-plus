#include <stdio.h>

void deleteElement(int i, int arr[])
{
    int so;
    printf("Muon nhap bao so: ");
    scanf("%d", &so);

    if (i < 0 || i >= so)
    {
        printf("i ko thuoc khoang cua arr\n");
        return;
    }

    for (int a = i; a < so - 1; a++)
    {
        arr[a] = arr[a + 1];
    }

    so--;

    for (int b = 0; b < so; b++)
    {
        printf("%d ", arr[b]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 4, 5, 1, 4, 6, 3, 6}, i;

    deleteElement(i, arr);

    return 0;
}
