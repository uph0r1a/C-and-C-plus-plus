#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, a[100];

    printf("Nhap so luong phan tu : ");
    scanf("%d", &n);

    printf("Nhap phan tu :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int lap = 1;

        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                lap = 0;
                break;
            }
        }

        if (lap)
        {
            count++;
        }
    }

    printf("So cac phan tu khac nhau la: %d\n", count);
    return 0;
}