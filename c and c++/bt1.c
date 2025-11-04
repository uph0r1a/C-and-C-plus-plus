#include "stdio.h"
int main()
{
	int nam_sinh;
	int tuoi;
	char ten[30];
	printf("nhap vao nam sinh cua ban: ");
	scanf("%d", &nam_sinh);
	printf("nhap ten cua ban: ");
	scanf("%s", ten);
	tuoi = 2024 - nam_sinh;
	printf("Ten toi la %s ,toi sinh nam %d nam nay toi %d tuoi", ten, nam_sinh, tuoi);
}