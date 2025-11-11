#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[100], so, vitri;

    printf("Muon nhap bao so: ");
    scanf("%d", &so);

    for (int i = 0; i < so; i++)
    {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap vitri can xoa: ");
    scanf("%d", &vitri);

    for (int i = vitri; i < so - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    so--;

    for (int i = 0; i < so; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}