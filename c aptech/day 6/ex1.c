#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[100], tong = 0, so;

    printf("Muon nhap bao so: ");
    scanf("%d", &so);

    for (int i = 0; i < so; i++)
    {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
        tong += arr[i];
    }

    printf("%d\n", tong);
    return 0;
}