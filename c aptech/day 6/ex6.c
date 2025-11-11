#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, target, arr[100];

    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Nhap gia tri target: ");
    scanf("%d", &target);

    int found = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                printf("Output: %d, %d\n", i, j);
                found = 1;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
    {
        printf("Khong co cap phan tu nao co tong bang %d\n", target);
    }
    return 0;
}