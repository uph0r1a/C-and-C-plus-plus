#include <stdio.h>
#include <string.h>

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
    int phuongan2;
    struct hoc_sinh dshocsinh[50];

    do
    {
        printf("\nNhap ten hs: ");
        fgets(dshocsinh[i].ten, 30, stdin);
        dshocsinh[i].ten[strcspn(dshocsinh[i].ten, "\n")] = '\0'; // bthg strcspn() se dem so ki tu o trg 1 string (VD hello thi se in ra 5 boi hello co 5 ki tu), nhung o trg TH nay thi strcspn se de xac dinh rang "\n" tiep theo se bang gia tri '\0' (null)

        printf("\nNhap nam sinh hs: ");
        scanf("%d", &dshocsinh[i].nam_sinh);

        printf("\nNhap diem hs: ");
        scanf("%f", &dshocsinh[i].diem);
        getchar();

        tong += dshocsinh[i].diem;

        printf("Co tiep tuc khong? - C/K : ");
        phuongan1 = getchar();
        getchar();
        i++;
    } while ((phuongan1 == 'C' || phuongan1 == 'c') && i < 50);

    average = tong / i;
    printf("Si so cua lop la: %d \nDiem trung binh la: %.2f\n", i, average);

    printf("Moi ban chon phuong an: ");
    printf("\n 0.Thoat \n 1.DSHS duoi va bang trung binh \n 2.DSHS tren trung binh? ");
    printf("\n Phuong an lua chon la: ");
    scanf("%d", &phuongan2);

    switch (phuongan2)
    {
    case 1:
    {
        printf("Nhung hs duoi va bang trung binh la: \n");
        for (int j = 0; j < i; j++)
        {
            if (dshocsinh[j].diem <= average)
            {
                printf("Ten: %s\nNam sinh: %d\nDiem: %.2f\n", dshocsinh[j].ten, dshocsinh[j].nam_sinh, dshocsinh[j].diem);
            }
        }
        break;
    }
    case 2:
    {
        printf("Nhung hs tren trung binh la: \n");
        for (int j = 0; j < i; j++)
        {
            if (dshocsinh[j].diem > average)
            {
                printf("Ten: %s\nNam sinh: %d\nDiem: %.2f\n", dshocsinh[j].ten, dshocsinh[j].nam_sinh, dshocsinh[j].diem);
            }
        }
        break;
    }
    }
    printf("TAM BIET CAC BAN !!!");
}