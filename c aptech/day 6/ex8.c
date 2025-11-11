#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, m, a[100], b[100];

    printf("Nhap so luong phan tu mang a: ");
    scanf("%d", &n);

    printf("Nhap cac phan tu cua mang a:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Nhap so luong phan tu mang b: ");
    scanf("%d", &m);

    printf("Nhap cac phan tu cua mang b:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    int daInRa[1000] = {0};

    printf("Cac so co trong ca hai mang la:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j] && daInRa[a[i]] == 0)
            {
                printf("%d ", a[i]);
                daInRa[a[i]] = 1;
                break;
            }
        }
    }
    printf("\n");
    return 0;
}