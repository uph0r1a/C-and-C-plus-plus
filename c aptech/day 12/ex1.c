#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int maSo;
    char hoTen[100];
    float diemTB;
} SinhVien;

void themSinhVien()
{
    FILE *f = fopen("sinhvien.txt", "ab");
    if (!f)
    {
        printf("Khong mo duoc file\n");
        return;
    }

    SinhVien sv;
    printf("Nhap ma so sv: ");
    scanf("%d", &sv.maSo);
    getchar();

    printf("Nhap ho ten sv: ");
    fgets(sv.hoTen, 100, stdin);
    sv.hoTen[strcspn(sv.hoTen, "\n")] = '\0';

    printf("Nhap diem tb: ");
    scanf("%f", &sv.diemTB);

    fwrite(&sv, sizeof(SinhVien), 1, f);
    fclose(f);
    printf("Da them sv\n");
}

void hienThiDanhSach()
{
    FILE *f = fopen("sinhvien.txt", "rb");
    if (!f)
    {
        printf("Khong mo duoc file\n");
        return;
    }

    SinhVien sv;

    while (fread(&sv, sizeof(SinhVien), 1, f))
    {
        printf("Ma so:%d\tTen:%s\tDiem tb:%.2f\n", sv.maSo, sv.hoTen, sv.diemTB);
    }

    fclose(f);
}

void timSinhVienTheoMaSo()
{
    int maSoCanTim;
    printf("Nhap ma so sv: ");
    scanf("%d", &maSoCanTim);

    FILE *f = fopen("sinhvien.txt", "rb");
    if (!f)
    {
        printf("Khong mo dc file\n");
        return;
    }

    SinhVien sv;
    int timThay = 0;
    while (fread(&sv, sizeof(SinhVien), 1, f))
    {
        if (sv.maSo == maSoCanTim)
        {
            printf("Tim thay sv:\n");
            printf("Ma so: %d\n", sv.maSo);
            printf("Ho ten: %s\n", sv.hoTen);
            printf("Diem tb: %.2f\n", sv.diemTB);
            timThay = 1;
            break;
        }
    }

    if (!timThay)
    {
        printf("Khong tim thay sv voi ma so %d.\n", maSoCanTim);
    }

    fclose(f);
}

void menu()
{
    printf("\nCHUONG TRINH QUAN LY SINH VIEN\n");
    printf("1. Them sinh vien moi vao file\n");
    printf("2. Hien thi danh sach sinh vien\n");
    printf("3. Tim sinh vien theo ma so\n");
    printf("4. Thoat chuong trinh\n");
    printf("Chon: ");
}

int main()
{
    int luaChon;

    do
    {
        menu();
        scanf("%d", &luaChon);
        getchar();

        switch (luaChon)
        {
        case 1:
            themSinhVien();
            break;
        case 2:
            hienThiDanhSach();
            break;
        case 3:
            timSinhVienTheoMaSo();
            break;
        case 4:
            break;
        default:
            printf("Chon sai, chon lai\n");
        }
    } while (luaChon != 4);

    return 0;
}
