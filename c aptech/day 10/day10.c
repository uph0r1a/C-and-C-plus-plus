// Bài 1. Viết chương trình nhập vào 2 phân số (gồm 2 số nguyên là tử số và mẫu số). Sau đó cộng, trừ, nhân, chia hai Phân Số đó và rút gọn phân số nếu có thể.#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int tu;
    int mau;
} PhanSo;

int rg(int a, int b)
{
    if (b == 0)
        return a;
    return rg(b, a % b);
}

int main(int argc, char const *argv[])
{
    PhanSo ps1, ps2, kq;
    int rutgon;

    printf("Nhap tu va mau cua phan so 1: ");
    scanf("%d %d", &ps1.tu, &ps1.mau);

    printf("Nhap tu va mau cua phan so 2: ");
    scanf("%d %d", &ps2.tu, &ps2.mau);

    if (ps1.mau == 0 || ps2.mau == 0)
    {
        printf("Mau so khac 0\n");
        return 1;
    }

    kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    rutgon = rg(abs(kq.tu), abs(kq.mau));
    kq.tu /= rutgon;
    kq.mau /= rutgon;
    if (kq.mau < 0)
    {
        kq.tu = -kq.tu;
        kq.mau = -kq.mau;
    }
    printf("Cong: %d/%d\n", kq.tu, kq.mau);

    kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    rutgon = rg(abs(kq.tu), abs(kq.mau));
    kq.tu /= rutgon;
    kq.mau /= rutgon;
    if (kq.mau < 0)
    {
        kq.tu = -kq.tu;
        kq.mau = -kq.mau;
    }
    printf("Tru: %d/%d\n", kq.tu, kq.mau);

    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    rutgon = rg(abs(kq.tu), abs(kq.mau));
    kq.tu /= rutgon;
    kq.mau /= rutgon;
    if (kq.mau < 0)
    {
        kq.tu = -kq.tu;
        kq.mau = -kq.mau;
    }
    printf("Nhan: %d/%d\n", kq.tu, kq.mau);

    if (ps2.tu == 0)
    {
        printf("Khong the chia cho 0\n");
    }
    else
    {
        kq.tu = ps1.tu * ps2.mau;
        kq.mau = ps1.mau * ps2.tu;
        rutgon = rg(abs(kq.tu), abs(kq.mau));
        kq.tu /= rutgon;
        kq.mau /= rutgon;
        if (kq.mau < 0)
        {
            kq.tu = -kq.tu;
            kq.mau = -kq.mau;
        }
        printf("Chia: %d/%d\n", kq.tu, kq.mau);
    }

    return 0;
}
// Bài 2. Nhập vào một danh sách lớp SinhVien(mã sinh viên, tên, giới tính, điểm toán, lý, hoá), yêu cầu xây dựng menu:
// 1.  Nhập và xuất ra thông tin của tất cả sinh viên.
// 2. Xuất sinh viên có điểm trung bình cao nhất.
// 3. Xuất sinh viên có điểm trung bình thấp nhất.
// 4. Tìm sinh viên có mã sinh viên là 123.
// 3. Tìm tất cả sinh viên có tên Nam.
// 4. Sắp xếp sinh viên thứ tự giảm dần theo điểm GPA.
// 5. Cập nhật thông tin của sinh viên có mã sinh viên 123.
// 6. Xóa sinh viên có mã sinh viên 123.
// 7. Thêm sinh viên ở vị trí thứ i.
// 8. Xóa tất cả sinh viên có giới tính Nam
#include <stdio.h>
#include <string.h>

typedef struct
{
    char maSV[20];
    char ten[50];
    char gioiTinh[10];
    float toan, ly, hoa;
    float GPA;
} SinhVien;

int main(int argc, char const *argv[])
{
    SinhVien ds[100];
    int n = 0, chon;

    do
    {
        printf("\nMENU\n");
        printf("1. Nhap va xuat thong tin cua tat ca sinh vien\n");
        printf("2. Xuat sinh vien co diem trung binh cao nhat\n");
        printf("3. Xuat sinh vien co diem trung binh thap nhat\n");
        printf("4. Tim sinh vien co ma sinh vien la 123\n");
        printf("5. Tim tat ca sinh vien co ten Nam\n");
        printf("6. Sap xep sinh vien thu tu giam dan theo diem GPA\n");
        printf("7. Cap nhat thong tin cua sinh vien co ma sinh vien 123\n");
        printf("8. Xoa sinh vien co ma sinh vien 123\n");
        printf("9. Them sinh vien o vi tri thu i\n");
        printf("10. Xoa tat ca sinh vien co gioi tinh Nam\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &chon);

        if (chon == 1)
        {
            printf("Nhap so sv: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("\nSV %d:\n", i + 1);
                printf("Ma SV: ");
                scanf("%s", ds[i].maSV);
                printf("Ten: ");
                scanf("%s", ds[i].ten);
                printf("Gioi tinh: ");
                scanf("%s", ds[i].gioiTinh);
                printf("Toan, Ly, Hoa: ");
                scanf("%f %f %f", &ds[i].toan, &ds[i].ly, &ds[i].hoa);
                ds[i].GPA = (ds[i].toan + ds[i].ly + ds[i].hoa) / 3;
            }

            printf("\nDanh sach sv:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%s - %s - %s - GPA: %.2f\n", ds[i].maSV, ds[i].ten, ds[i].gioiTinh, ds[i].GPA);
            }
        }

        else if (chon == 2)
        {
            float max = ds[0].GPA;
            for (int i = 1; i < n; i++)
                if (ds[i].GPA > max)
                    max = ds[i].GPA;
            for (int i = 0; i < n; i++)
                if (ds[i].GPA == max)
                    printf("%s - %s - GPA: %.2f\n", ds[i].maSV, ds[i].ten, ds[i].GPA);
        }

        else if (chon == 3)
        {
            float min = ds[0].GPA;
            for (int i = 1; i < n; i++)
                if (ds[i].GPA < min)
                    min = ds[i].GPA;
            for (int i = 0; i < n; i++)
                if (ds[i].GPA == min)
                    printf("%s - %s - GPA: %.2f\n", ds[i].maSV, ds[i].ten, ds[i].GPA);
        }

        else if (chon == 4)
        {
            int found = 0;
            for (int i = 0; i < n; i++)
                if (strcmp(ds[i].maSV, "123") == 0)
                {
                    printf("Tim thay: %s - %s\n", ds[i].maSV, ds[i].ten);
                    found = 1;
                }
            if (!found)
                printf("Khong thay!\n");
        }

        else if (chon == 5)
        {
            int found = 0;
            for (int i = 0; i < n; i++)
                if (strcmp(ds[i].ten, "Nam") == 0)
                {
                    printf("%s - %s\n", ds[i].maSV, ds[i].ten);
                    found = 1;
                }
            if (!found)
                printf("Khong co sv ten Nam.\n");
        }

        else if (chon == 6)
        {
            for (int i = 0; i < n - 1; i++)
                for (int j = i + 1; j < n; j++)
                    if (ds[i].GPA < ds[j].GPA)
                    {
                        SinhVien temp = ds[i];
                        ds[i] = ds[j];
                        ds[j] = temp;
                    }
            printf("Danh sach sap xep giam GPA:\n");
            for (int i = 0; i < n; i++)
                printf("%s - %s - GPA: %.2f\n", ds[i].maSV, ds[i].ten, ds[i].GPA);
        }

        else if (chon == 7)
        {
            for (int i = 0; i < n; i++)
            {
                if (strcmp(ds[i].maSV, "123") == 0)
                {
                    printf("Cap nhat sv ma 123:\n");
                    printf("Ten moi: ");
                    scanf("%s", ds[i].ten);
                    printf("Gioi tinh moi: ");
                    scanf("%s", ds[i].gioiTinh);
                    printf("Toan, Ly, Hoa moi: ");
                    scanf("%f %f %f", &ds[i].toan, &ds[i].ly, &ds[i].hoa);
                    ds[i].GPA = (ds[i].toan + ds[i].ly + ds[i].hoa) / 3;
                    break;
                }
            }
        }

        else if (chon == 8)
        {
            for (int i = 0; i < n; i++)
            {
                if (strcmp(ds[i].maSV, "123") == 0)
                {
                    for (int j = i; j < n - 1; j++)
                        ds[j] = ds[j + 1];
                    n--;
                    printf("Da xoa sv ma 123.\n");
                    break;
                }
            }
        }

        else if (chon == 9)
        {
            int i;
            if (n >= 100)
                break;
            printf("Nhap vi tri: ");
            scanf("%d", &i);
            if (i < 0 || i > n)
                break;
            for (int j = n; j > i; j--)
                ds[j] = ds[j - 1];
            printf("Nhap sv moi:\n");
            printf("Ma SV: ");
            scanf("%s", ds[i].maSV);
            printf("Ten: ");
            scanf("%s", ds[i].ten);
            printf("Gioi tinh: ");
            scanf("%s", ds[i].gioiTinh);
            printf("Toan, Ly, Hoa: ");
            scanf("%f %f %f", &ds[i].toan, &ds[i].ly, &ds[i].hoa);
            ds[i].GPA = (ds[i].toan + ds[i].ly + ds[i].hoa) / 3;
            n++;
        }

        else if (chon == 10)
        {
            int i = 0;
            while (i < n)
            {
                if (strcmp(ds[i].gioiTinh, "Nam") == 0)
                {
                    for (int j = i; j < n - 1; j++)
                        ds[j] = ds[j + 1];
                    n--;
                }
                else
                {
                    i++;
                }
            }
            printf("Da xoa sv gioi tinh Nam.\n");
        }

    } while (chon != 0);

    return 0;
}