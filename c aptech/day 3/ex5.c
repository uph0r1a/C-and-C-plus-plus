#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;

    printf("Nhap so n: ");
    scanf("%d", &n);

    int hangTram = (n / 100) % 10;
    if (hangTram < 0)
        hangTram = -hangTram; // xử lý số âm
    printf("Hang tram bang %d", hangTram);

    return 0;
}