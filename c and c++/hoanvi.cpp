#include <stdio.h>

void hoanvi(int *a, int *b);
void hoanvi(int *a, int *b)
{
	int c= *a;
	*a = *b;
	*b = c;
}

int main()
{
	;
	int so_dau;
	int so_hai;
	printf("Hay nhap so thu 1: ");
	scanf("%d", &so_dau);

	printf("Hay nhap so thu 2: ");
	scanf("%d", &so_hai);
	hoanvi(&so_dau, &so_hai);
	printf("%d %d",so_dau,so_hai);
}