#include <stdio.h>

int main()
{
    int so_luong = 100;

    int so_hang;
    int so[so_luong];
    int hang, cot = 10;

    printf("Hay nhap so so hang ban muon nhap (max %d): ", so_luong);
    scanf("%d", &so_hang);

    if (so_hang > so_luong)
    {
        printf("So so hang ban muon nhap vuot qua so so hang cho phep (%d).\n", so_luong);
        return 1;
    }

    hang = (so_hang + cot - 1) / cot;

    printf("Hay nhap so:\n");
    for (int i = 0; i < so_hang; i++)
    {
        scanf("%d", &so[i]);
    }

    for (int i = 0; i < so_hang - 1; i++)
    {
        for (int j = 0; j < so_hang - i - 1; j++)
        {
            if (so[j] > so[j + 1])
            {
                int k = so[j];
                so[j] = so[j + 1];
                so[j + 1] = k;
            }
        }
    }

    printf("Sau khi sap xep:\n");
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            int l = i * cot + j;
            if (l < so_hang)
            {
                printf("%d ", so[l]);
            }
        }
    }
}
