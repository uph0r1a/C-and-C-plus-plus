#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[100], so, vitri, somoi;

    printf("Muon nhap bao so: ");
    scanf("%d", &so);

    for (int i = 0; i < so; i++)
    {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap so can them: ");
    scanf("%d", &somoi);
    printf("Nhap vitri: ");
    scanf("%d", &vitri);

    for (int i = so; i > vitri; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[vitri] = somoi;
    so++;

    for (int i = 0; i < so; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}