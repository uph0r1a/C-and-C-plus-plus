#include <stdio.h>
#include <string.h>

float maxElement(float mangdl[], int size);
float minElement(float mangdl[], int size);

float maxElement(float mangdl[], int size)
{
    float max = mangdl[0];
    for (int j = 1; j < size; j++)
    {
        if (mangdl[j] > max)
            max = mangdl[j];
    }
    return max;
}

float minElement(float mangdl[], int size)
{
    float min = mangdl[0];
    for (int j = 1; j < size; j++)
    {
        if (mangdl[j] < min)
            min = mangdl[j];
    }
    return min;
}

struct hoc_sinh
{
    char ten[30];
    int nam_sinh;
    float diem;
};

int main()
{
    int i = 0;
    char phuongan1;
    float tong = 0;
    float average;
    struct hoc_sinh dshocsinh[50];
    float scores[50];

    do
    {
        printf("\nNhap ten hs: ");
        fgets(dshocsinh[i].ten, 30, stdin);
        dshocsinh[i].ten[strcspn(dshocsinh[i].ten, "\n")] = '\0';

        printf("\nNhap nam sinh hs: ");
        scanf("%d", &dshocsinh[i].nam_sinh);

        printf("\nNhap diem hs: ");
        scanf("%f", &dshocsinh[i].diem);
        getchar();

        scores[i] = dshocsinh[i].diem;
        tong += dshocsinh[i].diem;

        printf("Co tiep tuc khong? - C/K : ");
        phuongan1 = getchar();
        getchar();
        i++;
    } while ((phuongan1 == 'C' || phuongan1 == 'c') && i < 50);

    average = tong / i;
    printf("Si so cua lop la: %d \nDiem trung binh la: %.2f\n", i, average);

    float hsmax = maxElement(scores, i);
    float hsmin = minElement(scores, i);

    for (int j = 0; j < i; j++)
    {
        if (dshocsinh[j].diem == hsmax)
        {
            printf("Hoc sinh co diem cao nhat lop la %s sinh nam %d voi so diem %.2f \n", dshocsinh[j].ten, dshocsinh[j].nam_sinh, dshocsinh[j].diem);
            break;
        }
    }

    for (int j = 0; j < i; j++)
    {
        if (dshocsinh[j].diem == hsmin)
        {
            printf("Hoc sinh co diem thap nhat lop la %s sinh nam %d voi so diem %.2f \n", dshocsinh[j].ten, dshocsinh[j].nam_sinh, dshocsinh[j].diem);
            break;
        }
    }

    return 0;
}
