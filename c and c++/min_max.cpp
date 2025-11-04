#include <stdio.h>

int maxElement(int mangdl[10]);
int minElement(int mangdl[10]);

int maxElement(int mangdl[10])
{
	int max = 0;
	int j;
	for (j = 0; j < 10; j++)
	{
		if (mangdl[j] > mangdl[max])
			max = j;
	}
	return max;
}

int minElement(int mangdl[10])
{
	int min = 0;
	int j;
	for (j = 0; j < 10; j++)
	{
		if (mangdl[j] < mangdl[min])
			min = j;
	}
	return min;
}

int main()
{
	int i = 0;
	int x[10];
	int tong = 0;
	int chisomax, chisomin;
	// nhap du lieu cho mang
	for (i = 0; i < 10; i++)
	{
		printf("Hay nhap phan tu %d cua mang du lieu: ", i + 1);
		scanf("%d", &x[i]);
		tong = tong + x[i];
	}

	// Tim phan tu Lon nhat trong mang du lieu
	chisomax = maxElement(x);
	printf("Phan tu thu %d co gia tri lon nhat la %d \n", chisomax + 1, x[chisomax]);
	// Tim phan tu nho nhat
	chisomin = minElement(x);
	printf("Phan tu thu %d co gia tri nho nhat la %d \n", chisomin + 1, x[chisomin]);

	// Tong cac phan tu
	printf("Tong cua mang du lieu la %d \n", tong);
}
