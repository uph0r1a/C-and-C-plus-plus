#include <stdio.h>
#include <math.h>

int main()
{
    FILE *f1, *f2;
    f1 = fopen("input.txt", "r");
    if (f1 == NULL)
    {
        printf("Khong mo duoc file\n");
    }
    else
    {
        f2 = fopen("output.txt", "w");
        int n, x;
        fscanf(f1, "%d", &n);
        for (int i = 0; i < n; i++)
        {
            fscanf(f1, "%d", &x);
            fprintf(f2, "%d ", x);
        }
        fclose(f1);
        fclose(f2);
    }
    return 0;
}