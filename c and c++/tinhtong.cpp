#include <stdio.h>

int main()
{
	int a[10] = {3, 5, 7, 1, 2, 9, 4, 6, 8, 9};
	int tong;
	int i = 0;
	tong = 0;
	while (tong < 30)
	{
		tong = tong + a[i];
		i = i + 1;
	}
	printf("tong gia tri la %d tinh den phan tu thu %d", tong, i - 1);
}