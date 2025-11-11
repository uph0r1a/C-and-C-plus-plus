#include <stdio.h>

int main(int argc, char const *argv[])
{
    float toan, ly, hoa, trungbinh;

    printf("Nhap diem toan: ");
    scanf("%f", &toan);
    printf("Nhap diem ly: ");
    scanf("%f", &ly);
    printf("Nhap diem hoa: ");
    scanf("%f", &hoa);

    trungbinh = (toan + ly + hoa) / 3;

    if (trungbinh >= 8)
        printf("Gioi");
    else if (trungbinh >= 6.5)
        printf("Kha");
    else if (trungbinh >= 5)
        printf("Trung binh");
    else if (trungbinh >= 3.5)
        printf("Yeu");
    else
        printf("Kem");

    return 0;
}