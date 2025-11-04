#include <stdio.h>

void hoanvi(int *a, int *b);
void sap_xep(int mangcansx[], int ktmang);
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
    while (j < ktmang - 1) // Ensure the correct loop bounds
    {
        for (i = j + 1; i < ktmang; i++)
        {
            if (mangcansx[i] < mangcansx[j])
            {
                hoanvi(&mangcansx[i], &mangcansx[j]); // Pass pointers to hoanvi
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

    // Input data for array
    printf("Ban muon nhap bao nhieu so (toi da 10): ");
    scanf("%d", &so_pt);

    if (so_pt > 10)
    {
        printf("So phan tu qua lon, toi da la 10.\n");
        return 1; // Exit with error code
    }

    for (so_hang = 0; so_hang < so_pt; so_hang++)
    {
        printf("Hay nhap so thu %d: ", so_hang + 1);
        scanf("%d", &a[so_hang]);
    }

    // Sort the data in ascending order
    sap_xep(a, so_pt);

    // Print sorted data
    printf("Mang sau khi sap xep:\n");
    for (int k = 0; k < so_pt; k++)
    {
        printf("%d ", a[k]);
    }
    printf("\n");

    return 0;
}
