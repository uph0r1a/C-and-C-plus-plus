#include <stdio.h>

void hoanvi(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void sap_xep(int mangcansx[], int ktmang)
{
    int j = 0;
    int i;
    while (j < ktmang - 1)
    {
        for (i = j + 1; i < ktmang; i++)
        {
            if (mangcansx[i] < mangcansx[j])
            {
                hoanvi(&mangcansx[i], &mangcansx[j]);
            }
        }
        j++;
    }
}

int main()
{
    int a[10];
    int so_hang;
    int so_pt;

    printf("Ban muon nhap bao nhieu so (toi da 10): ");
    scanf("%d", &so_pt);

    if (so_pt > 10)
    {
        printf("So phan tu qua lon, toi da la 10.\n");
        return 1;
    }

    for (so_hang = 0; so_hang < so_pt; so_hang++)
    {
        printf("Hay nhap so thu %d: ", so_hang + 1);
        scanf("%d", &a[so_hang]);
    }

    sap_xep(a, so_pt);

    printf("Mang sau khi sap xep:\n");
    for (int k = 0; k < so_pt; k++)
    {
        printf("%d ", a[k]);
    }
    printf("\n");

    return 0;
}
