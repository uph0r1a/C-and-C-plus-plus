#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, a[100], daXet[100];

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    printf("Nhap phan tu:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        daXet[i] = 0;
    }

    printf("Ket qua:\n");
    for (int i = 0; i < n; i++)
    {
        if (daXet[i] == 1)
        {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
                daXet[j] = 1;
            }
        }

        printf("%d xuat hien %d lan\n", a[i], count);
    }
    return 0;
}