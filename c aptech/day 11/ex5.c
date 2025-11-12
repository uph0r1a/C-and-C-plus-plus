#include <stdio.h>
#include <string.h>

typedef struct
{
    char maSV[20];
    char ten[50];
    char gioiTinh[10];
    float toan, ly, hoa;
} SinhVien;

int main()
{
    SinhVien ds[100];
    int n = 0, chon;

    do
    {
        printf("\nMENU\n");
        printf("1. Nhap thong tin sinh vien\n");
        printf("2. Xuat thong tin sinh vien\n");
        printf("3. Ghi thong tin vao file\n");
        printf("4. Doc file va hien thi danh sach sinh vien\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &chon);

        if (chon == 1)
        {
            printf("Nhap so sinh vien: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("SV %d\n", i + 1);
                printf("Ma SV: ");
                scanf("%s", ds[i].maSV);
                getchar();

                printf("Ten: ");
                fgets(ds[i].ten, sizeof(ds[i].ten), stdin);

                printf("Gioi tinh: ");
                scanf("%s", ds[i].gioiTinh);

                printf("Nhap diem Toan, Ly, Hoa: ");
                scanf("%f %f %f", &ds[i].toan, &ds[i].ly, &ds[i].hoa);
            }
        }
        else if (chon == 2)
        {
            if (n == 0)
            {
                printf("Chua co du lieu sinh vien\n");
            }
            else
            {
                printf("\nDanh sach sinh vien\n");
                for (int i = 0; i < n; i++)
                {
                    printf("%s\t%s\t%s\t%.2f\t%.2f\t%.2f\n",ds[i].maSV, ds[i].ten, ds[i].gioiTinh,ds[i].toan, ds[i].ly, ds[i].hoa);
                }
            }
        }
        else if (chon == 3)
        {
            if (n == 0)
            {
                printf("Chua co du lieu sinh vien\n");
            }
            else
            {
                FILE *f = fopen("sv.txt", "w");
                if (f == NULL)
                {
                    printf("Khong mo duoc file\n");
                }
                else
                {
                    fprintf(f, "Danh sach sinh vien\n");
                    for (int i = 0; i < n; i++)
                    {
                        fprintf(f, "%s\t%s\t%s\t%.2f\t%.2f\t%.2f\n",ds[i].maSV, ds[i].ten, ds[i].gioiTinh,ds[i].toan, ds[i].ly, ds[i].hoa);
                    }
                    fclose(f);
                }
            }
        }
        else if (chon == 4)
        {
            FILE *f = fopen("sv.txt", "r");
            if (f == NULL)
            {
                printf("Khong mo duoc file\n");
            }
            else
            {
                char dong[200];
                printf("\nDanh sach sinh vien\n");
                while (fgets(dong, sizeof(dong), f) != NULL)
                {
                    printf("%s", dong);
                }
                fclose(f);
            }
        }
        else if (chon > 4)
        {
            printf("Chon sai.Chon lai\n");
        }

    } while (chon != 0);

    return 0;
}
