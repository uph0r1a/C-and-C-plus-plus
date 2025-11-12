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