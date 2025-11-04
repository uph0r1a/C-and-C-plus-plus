#include <stdio.h>

void thapHN(int dia, char cot1, char cot3, char cot2)
{
    if (dia == 1)
    {
        printf("Chuyen dia 1 tu cot %c sang cot %c\n", cot1, cot3);
        return;
    }
    thapHN(dia - 1, cot1, cot2, cot3);
    printf("Chuyen dia %d tu cot %c sang cot %c\n", dia, cot1, cot3);
    thapHN(dia - 1, cot2, cot3, cot1);
}

int main()
{
    int dia;

    printf("Nhap so dia: ");
    scanf("%d", &dia);

    thapHN(dia, '1', '3', '2');
}
