#include <stdio.h>

int main()
{
	float luong;
	printf("hay nhap luong cua ban: ");
	scanf("%f", &luong);
	if (luong >= 2000)
		printf("LUONG BAN QUA CAO");
	else
		printf("LUONG BAN QUA THAP");
}